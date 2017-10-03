
#include "ClientOpsServer.h"

#include "ops.h"
#include "wal_user.h"

#include <iostream>
#include <string>

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

void send_records(int count, ClientOpsServerClient &client) {
	
	ClientOpsArguments ops;
	ClientOpsRetval retval;
	string key = "key",  value = "value";
	for (int i = 0;  i < count; i++) {
		string temp = to_string(i);
		key = "key" + temp;
		value = "value" + temp;
		ops.op_type = OP_INSERT;
		ops.key = key;
		ops.value = value;
		cout <<"\nSending Ops Key: " << key << " Value: "<< value << endl;
		client.submit_ops(retval, ops);
    	retval.printTo(cout);
	}
}

int main () {
    int port = 9090;
    boost::shared_ptr<TTransport> socket(new TSocket("localhost", port));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol (new TBinaryProtocol(transport));

    ClientOpsServerClient client(protocol);
	transport->open();

	send_records(10, client);
	transport->close();
	return 0;
}
