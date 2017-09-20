#! /usr/bin/python3.4

import proto
import socket
from collections import deque
import threading
import time
from proto import print_red, print_green, print_blue


operations = {}
ops_queue = deque()
notification_queue = deque()
notification_dict = {}

kv_dict = {}

def send_notification():
    """ Function to just pick the elements from the queue and send the
    notification to the client."""

    global notification_queue, notification_dict
    print ("Waiting for client connection")
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', proto.ACK_PORT))
    s.listen(1)
    conn, addr = s.accept()

    time.sleep(10)
    print("Printing notification quque", list(notification_queue))
    print ('Notification thread connected by', addr)
    print ("Connection object is ", conn)
    sleep_time=1
    while True:
        print ("Sleeping for {0} seconds in send notification".format(sleep_time))
        time.sleep(sleep_time)
        print("Printing notification quque", list(notification_queue))
        try:
            seq_num = notification_queue.popleft()

            message = proto.get_notification_message(seq_num, notification_dict[seq_num])
            proto.send_reply(conn, message)
            notification_dict.pop(seq_num)
        except IndexError as e:
            print ("No notification to process in send notification")
        except Exception as e:
            print ("Got exception here 1", e)

def queue_processor():
    """ Function to take the elements out of the queue and then process the
    request stored in the dictionary.  Once the request is processed then move
    the element to the notification_queue where another thread will pick up the
    request and send to the client stating wheter the request is complete or
    no.
    """
    print ("Running the queue processor")
    sleep_time=.2
    global notification_queue, notification_dict, operations, ops_queue

    while True:
        print ("Sleeping for {0} seconds in queue processor".format(sleep_time))

        time.sleep(sleep_time)

        try:
            seq_num = ops_queue.popleft()
            print ("Processing Seq Number {0}".format(seq_num))
            command = operations[seq_num]
            notification_queue.append(seq_num)
            print("Printing Notification List", list(notification_queue))
            if process_ops(command, seq_num) is True:
                notification_dict[seq_num] = True
            else:
                notification_dict[seq_num] = False

        except IndexError as e:
            pass
            #print ("No elements to process")


def process_ops(command, seq_num):
    """ Function to process the elements in the queue. """
    if seq_num % 5 != 0:
        kv_dict[command.key] = command.value
        return True
    else:
        return False

def add_ops(command, seq_num):
    """Function to add the request to the queue. """
    global ops_queue, operations
    operations[seq_num] = command
    ops_queue.append(seq_num)
    print("Ops queue is ", list(ops_queue))

def command_loop():
    """The main command loop. This loop will wait for connections and then
    on getting a connection wait for to receive a command from the clients.

    Based on the client the loop will execute the related function and send
    the reply to the client."""

    start_thread_procesors()
    start_notification_thread()

    print ("Waiting for connection")
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', proto.PORT))
    s.listen(1)

    conn, addr = s.accept()
    print ('Connected by', addr)

    while True:

        command, seq_num = proto.recv_command(socket=None, connection=conn)

        # No error checking here. Just recieve the command and send an reply that the 
        # command has been received.
        add_ops(command, seq_num)

        print ("Command is {0}".format(command))
        message = proto.get_error_message(0, "success", 0)
        proto.send_reply(conn, message)
#        conn.close()

threadList = []

def start_notification_thread():
    print ("Starting notification thread")
    t = threading.Thread(target=send_notification)
    t.start()
    global threadList
    threadList.append(t)

def start_thread_procesors():
    count=proto.THREAD_PROCESSORS
    for i in range(count):
        t = threading.Thread(target=queue_processor)
        t.start()
        global threadList
        threadList.append(t)

if __name__ == "__main__":

    command_loop()

