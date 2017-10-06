INCLUDE_FLAGS=-Iinclude -Igen-cpp -I/usr/local/include/thrift
CPPFLAGS=-Wall -std=c++17

ALL_FLAGS=$(INCLUDE_FLAGS) $(CPPFLAGS)

all: clean master client slave
compile:
	g++ -g  -c $(ALL_FLAGS)  cpp/*.cpp gen-cpp/*.cpp client/*.cpp slave/*.cpp

slave: compile
	g++ -g -L/usr/local/lib MyMap.o SlaveLocal.o MainSlave.o SlaveOpsServer.o wal_constants.o   wal_types.o -o Slave -std=c++17 -lthrift
	
master: compile
	rm -rf Master 2>/dev/null
	g++ -g -L/usr/local/lib SlaveOpsServer.o SlaveManager.o wal_constants.o OpsReplicator.o MainMasterServer.o wal_types.o SlaveLocal.o MyMap.o  ClientOpsServer.o  -o Master  -std=c++17 -lthrift

client: compile
	g++ -g -L/usr/local/lib wal_constants.o ClientMain.o wal_types.o -o CClient -lthrift ClientOpsServer.o

clean:
	rm -rf *.o

