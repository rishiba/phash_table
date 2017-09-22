// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Something.h"
#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;
using namespace std;

using namespace  ::Test;

class SomethingHandler : virtual public SomethingIf {
 public:
  SomethingHandler() {
    // Your initialization goes here
  }

  int32_t ping() {
    // Your implementation goes here
    printf("ping\n");
	return 0;
  }


	void print_ops(Ops passed_value) {
	cout << "\nPrinting num " << passed_value.num;
	cout << "\nPrinting key " << passed_value.key;
	cout << "\nPrinting value " << passed_value.value;
	cout << "\nPrinting address " << passed_value;
	}
  int32_t send_ops(const Ops& passed_value, const Ops_ACK& retval) {
    // Your implementation goes here
    printf("send_ops\n");
	print_ops(passed_value);
	return 0;
		
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  cout <<"\nStarting server";
  shared_ptr<SomethingHandler> handler(new SomethingHandler());
  shared_ptr<TProcessor> processor(new SomethingProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  cout <<"\nStarting server";
  server.serve();
  return 0;
}

