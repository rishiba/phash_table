INCLUDE_FLAGS=-Iinclude -Igen-cpp -I/usr/local/include/thrift
CPPFLAGS=-Wall -std=c++17

ALL_FLAGS=$(INCLUDE_FLAGS) $(CPPFLAGS)

compile:
	g++ -c $(ALL_FLAGS)  cpp/*.cpp gen-cpp/*.cpp

master: compile
	g++ -L/usr/local/lib -lthrift wal_constants.o OpsReplicator.o MainMasterServer.o wal_types.o SlaveLocal.o MyMap.o  ClientOpsServer.o  -o Master  -std=c++17


clean:
	rm -rf *.o
