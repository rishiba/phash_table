#! /bin/bash

rm *o
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c PhashServer.cpp -o PhashServer.o
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c ServerPhashServer.cpp -o server.o
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_constants.cpp -o constants.o
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_types.cpp -o types.o

g++ -std=c++11 -L/usr/local/lib constants.o  PhashServer.o  server.o  types.o -o Server -lthrift

