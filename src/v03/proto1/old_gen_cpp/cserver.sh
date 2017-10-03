
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c PhashServer.cpp
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c MainPhashServer.cpp
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_constants.cpp -o constants.o
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_types.cpp -o types.o

