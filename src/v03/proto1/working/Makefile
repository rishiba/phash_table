clean:
	$(RM) *.o something_server something_client

compile:
	g++ -std=c++11 -Wall -Iinclude -I/usr/local/include/thrift -c MainSlaveHandler.cpp -o MainSlaveHandler.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c PhashServer.cpp -o PhashServer.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c ServerPhashServer.cpp -o server.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_constants.cpp -o constants.o
	g++ -std=c++11 -Wall -I/usr/local/include/thrift -c wal_types.cpp -o types.o


MasterMain: compile
	g++ -std=c++11 -Wall -Iinclude -I/usr/local/include/thrift -c MasterMain.cpp -o MasterMain.o

ClientMain: compile
	g++ -std=c++11 -Wall -Iinclude -I/usr/local/include/thrift ClientMain.cpp -c

slave:
	g++ -L/usr/local/lib constants.o  PhashServer.o  client.o  types.o MainSlaveHandler.o -o Slave -lthrift

client:
	g++ -Wall -Iinclude -I/usr/local/include/thrift -c ClientPhashServer.cpp -o client.o -std=c++11
	g++ -L/usr/local/lib constants.o  PhashServer.o  client.o  types.o -o CClient -lthrift

server:
	g++ -L/usr/local/lib -std=c++11 -Wall -Iinclude -I/usr/local/include/thrift PhashServer.cpp MainPhashServer.cpp wal_constants.cpp wal_types.cpp OpsReplicator.cpp MyMap.cpp Slave.cpp SlaveLocal.cpp  -lthrift SlaveManager.cpp -o Server

server2:
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
