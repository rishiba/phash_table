#include "wal_types.h"
#include <SlaveOpsServer.h>
#include "SlaveManager.h"
#include <cstdint>
#include <iostream>
#include "wal_user.h"
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

// using namespace apache::thirft;
// using namespace apache::thirft::protocol;
// using namespace apache::thirft::transport;

using namespace std;

using boost::shared_ptr;
void print_queue(std::queue <std::int64_t> q) {
}

void print_map(std::unordered_map<std::int64_t, void *> mymap) {
	for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for ( auto local_it = mymap.cbegin(i); local_it!= mymap.cend(i); ++local_it )
			std::cout << " " << local_it->first << ":" << local_it->second;
		std::cout << std::endl;
	}
}

SlaveManager::SlaveManager(int port, std::string host) {

    std::cerr <<"\nInitializing port with " << port << " host as " << host;
    
    boost::shared_ptr<TTransport> socket(new TSocket(host, port));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol (new TBinaryProtocol(transport));

    client = new SlaveOpsServerClient(protocol);
    std::cerr <<"\nPinging the client";

	transport->open();
    Ping_ACK p;
    client->ping(p);

 // 	transport->close(); // TODO move into destructor.
}

int SlaveManager::submit_ops(SlaveOpsArguments *ops) {
    // Add the ops to the queue and the map. Then signal the process_in_progress_records to wake up.

    // Take the lock on the in_progress queue.
    // Take the lock on the condition variable mutex.
    // Add the ops into the queue.
    // Release the lock on the queue and signal the condition variable.
	std::cerr <<"\nAdding to the quque";
	in_progress.push(ops->seq_number);

	auto pair = std::make_pair (ops->seq_number, ops);

	std::cerr <<"\nAdding to the map";
	seq_vs_ops.emplace(pair);
	print_map(seq_vs_ops);

	SlaveOpsRetval ack;
    SlaveOpsArguments &ops_ref = *ops;
    SlaveOpsArguments temp;
    
    temp.op_type = 1;
    temp.key = "rishi";
    temp.value = "agrawal";
    temp.seq_number = 56;
	std::cerr <<"\nSending ops to slave";
	//client->submit_ops_to_slave(ack, temp);
	client->submit_ops_to_slave(ack, ops_ref);
	std::cerr <<"\nSent ops to slave";

    return SUCCESS;
}

int SlaveManager::process_in_progress_records(void) {
    /* Function to read the in_progress queue and then send the records to the connected SlaveClient . */
    return ERR_INCORRECT_PLACE_TO_RETURN;
}

int SlaveManager::process_done_records(void) {
    /* Function to read the done queue and reduce the reference count from the seq_ops_map */
    return ERR_INCORRECT_PLACE_TO_RETURN;
}

