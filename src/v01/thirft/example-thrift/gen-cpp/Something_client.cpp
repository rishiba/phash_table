
#include "Something.h"  // As an example

#include <iostream>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Test;
using namespace std;

int main(int argc, char **argv) {
	boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	SomethingClient client(protocol);
	transport->open();
	client.ping();
	Ops passed_value;
    passed_value.num = 1;
    passed_value.key = "hello";
    passed_value.value = "world";
    passed_value.address = "address is this";
	Ops_ACK retval;
	client.send_ops(passed_value, retval);

	cout << "\nPrinting the retval " << retval.errnum << " return string " << retval.errMsg << endl;
	transport->close();

	return 0;
}

