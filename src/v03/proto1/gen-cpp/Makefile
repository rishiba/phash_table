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


test:
	g++ -std=c++11 -Wall testMyMap.cpp MyMap.cpp -o myMaptest
	g++ -std=c++11 -Wall testSlaveLocal.cpp SlaveLocal.cpp MyMap.cpp wal_types.cpp -o slaveLocaltest
