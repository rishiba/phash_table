#! /usr/bin/python3.4

import socket
import threading
from pprint import pprint
import proto

import time
seq_dict = {}

def recv_ack():
    """ Function to receive ack for the requested actions. Once the ACK is received
    the thread should remove the key from the seq_dict - but for now - it is just updating the state.

    if (seq_num % 5 == 0) then { the ack will be having False }
    """

    # This thread will keep on reading for the ACKs of the requests sent.
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print ("Notification: Port is ", proto.ACK_PORT)
    s.connect(("localhost", proto.ACK_PORT))

    while True:
        time.sleep(1)
        print ("Notification: Waiting for notification")
        retval, seq_num = proto.recv_command(socket=s)
        print ("Notification: Got ack for {0} value as {1}, seq_num is {2}".format(retval.seq_num, retval.success, seq_num))

        try:
            seq_dict[retval.seq_num] = retval.success
        except Exception as e:
            print ("Got exception as ", e)

threadList = []

def start_ack_thread():

    t = threading.Thread(target=recv_ack)
    t.start()
    global threadList
    threadList.append(t)

if __name__ == "__main__":

    start_ack_thread()

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print ("Port is ", proto.PORT)
    s.connect(("localhost", proto.PORT))

    for i in range(1, 20):
        key = "key" + str(i)
        value = "value" + str(i)
        seq_num = i

        print ("Adding new key {0} and value {1}".format(key, value))

        message = proto.get_kv_message(key, value, seq_num)
        # Once we send the request - we wait for the initial ack - which only says that
        # the request has been received. 
        retval, seq_number = proto.send_and_recv_reply(s, message)

        pprint (retval.errno)

        if int(retval.errno) == 0:
            print ("Addition of key {0} value {1} is in progress".format(key, value))
            # We add the seq number to a dict to maintain the packages which we have sent
            # to the server.
            seq_dict[seq_num] = None
        else:
            print ("Could not add the key {0} value {1}".format(key, value))

        #pprint(seq_dict)

        time.sleep(.3)

    pprint(seq_dict)

    t = threadList[0]
    t.join()
