from collections import namedtuple
import struct
import socket

DEBUG=0

WARNING = '\033[31m'
ENDC = '\033[0m'
OKGREEN = '\033[32m'

def print_red(message):
    """Function to print a message in RED."""
    print(WARNING + message + ENDC)

def print_green(message):
    """Function to print a message in GREEN."""
    print(OKGREEN + message + ENDC)

def print_blue(message):
    """Function to print a message in GREEN."""
    if DEBUG != 0:
        print(OKGREEN + message + ENDC)

error_packet = namedtuple("error_packet", "errno errmsg")
insert_record = namedtuple("insert_record", "key value")
req_descriptor = struct.Struct("!III") 
seq_info = namedtuple("seq_info", "seq_num success")

THREAD_PROCESSORS=1

import pickle

PORT=40001
ACK_PORT=50001
    
def get_kv_message(key, value, seq_num):
    """ Make the data a pickle, take the length, take the SHA1SUM. Put them
        into a struct.

        Append the struct with the pickle
    """

    data = insert_record(key, value)
    return get_message(data, seq_num)
    
def read_bytes(handle, size):
    
    bytes_read = 0
    data = None
    retval = None
    to_read = size
    
    while True:
        data = handle.recv(to_read)
        if retval is None:
            # We have not recieved anything yet.
            retval = data
        else:
            retval = retval + data

        bytes_read = len(retval)
        if bytes_read == size:
            return retval
        else:
            to_read = size - bytes_read
    
def recv_command(socket=None, connection=None):
    """ Recieve the messages. 
        For servers it is a connection, and for clients it is socket."""

    if socket is not None:
        print ("Reading from socket. In client")
        handle = socket
    else:
        print ("Reading from connection. In server")
        handle = connection

    # This will keep on reading and I will have to loop over here
    # and break the loop when I see some data.
    req_des = read_bytes(handle, req_descriptor.size)

    print_blue ("req_descriptor is {0} length is {1}".format(req_des, len(req_des)))

    payload_length, req_num, seq_num = req_descriptor.unpack(req_des)

    print_blue ("req_num is {0} payload_length is {1}".format(req_num, payload_length))

    if payload_length != 0:
        payload = read_bytes(handle, payload_length)
        print_blue ("Payload is {0}".format(payload))
        unpickled_data = pickle.loads(payload)
    else:
        print_blue ("Error in reciving data")

    return unpickled_data, seq_num

def recv_command2(socket=None, connection=None):
    """ Recieve the messages. 
        For servers it is a connection, and for clients it is socket."""

    if socket is not None:
        print ("Reading from socket. In client")
        handle = socket
    else:
        print ("Reading from connection. In server")
        handle = connection

    # This will keep on reading and I will have to loop over here
    # and break the loop when I see some data.
    req_des = handle.recv(req_descriptor.size)

    print ("req_descriptor is {0} length is {1}".format(req_des, len(req_des)))

    payload_length, req_num, seq_num = req_descriptor.unpack(req_des)

    print ("req_num is {0} payload_length is {1}".format(req_num, payload_length))

    if payload_length != 0:
        payload = handle.recv(payload_length)
        print ("Payload is {0}".format(payload))
        unpickled_data = pickle.loads(payload)
    else:
        print ("Error in reciving data")


    return unpickled_data


def get_message(data, seq_num):
    pickled_data = pickle.dumps(data)
    payload_length = len(pickled_data)
    req_num = 1

    print_blue ("Payload length {0} req_num {1}".format(payload_length, req_num))
    header = req_descriptor.pack(payload_length, req_num, seq_num)
    message = header + pickled_data
    print_blue ("Pickled Data is {0}".format(pickled_data))
    return message

def get_error_message(errno, errmsg, seq_num):
    
    data = error_packet(errno, errmsg)
    return get_message(data, seq_num)

def get_notification_message(seq_num, success):
    message = seq_info(seq_num, success)
    return get_message(message, seq_num)
    

def send_reply(s, message):
    try:
        s.sendall(message)
    except Exception as e:
        print ("Exception in send reply", e)

def send_message(s, message):

    s.sendall(message)

def send_and_recv_reply(s, message):
    """ Function to send a message to the provided IP and PORT and get back the
        reply.

        Make a connection -> Send the base packet -> send the payload packet (if any) -> wait for reply of the payload_descriptor -> return the reply_payload after checking the SHA1SUM.

    """
    s.sendall(message)
    data = recv_command(s, connection=None)
    print_blue (data)
    return data

def send_message2(connection):
    message = get_message()
    print_blue ("Length of the message is {0}".format(message))
    connection.sendall(message)
