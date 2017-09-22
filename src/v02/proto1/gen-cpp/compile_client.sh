#! /bin/bash

g++ -Wall -I/usr/local/include/thrift -c ClientPhashServer.cpp -o client.o -std=c++11

g++ -L/usr/local/lib constants.o  PhashServer.o  client.o  types.o -o Client -lthrift
