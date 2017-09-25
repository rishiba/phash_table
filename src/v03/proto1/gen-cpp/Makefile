GEN_SRC := PhashServer.cpp wal_constants.cpp wal_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR)

.PHONY: all clean

all: ServerPhashServer ClientPhashServer

%.o: %.cpp
	$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@

something_server: ServerPhashServer.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift 

something_client: ClientPhashServer.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift 

clean:
	$(RM) *.o something_server something_client

client:
	g++ -Wall -I/usr/local/include/thrift -c ClientPhashServer.cpp -o client.o -std=c++11
	g++ -L/usr/local/lib constants.o  PhashServer.o  client.o  types.o -o CClient -lthrift

server:
	rm *o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c PhashServer.cpp -o PhashServer.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c ServerPhashServer.cpp -o server.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_constants.cpp -o constants.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_types.cpp -o types.o
	g++ -std=c++11 -L/usr/local/lib constants.o  PhashServer.o  server.o  types.o -o SServer -lthrift


test:
	g++ -std=c++11 -Wall testMyMap.cpp MyMap.cpp -o myMaptest
	g++ -std=c++11 -Wall testSlaveLocal.cpp SlaveLocal.cpp MyMap.cpp wal_types.cpp Slave.cpp -o slaveLocaltest
	g++ -std=c++11 -Wall testOpsReplicator.cpp MyMap.cpp SlaveLocal.cpp Slave.cpp OpsReplicator.cpp wal_types.cpp -o testOpsReplicator
