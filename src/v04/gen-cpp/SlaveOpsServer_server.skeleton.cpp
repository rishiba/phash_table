// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "SlaveOpsServer.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class SlaveOpsServerHandler : virtual public SlaveOpsServerIf {
 public:
  SlaveOpsServerHandler() {
    // Your initialization goes here
  }

  void ping(Ping_ACK& _return) {
    // Your implementation goes here
    printf("ping\n");
  }

  void submit_ops_to_slave(SlaveOpsRetval& _return, const SlaveOpsArguments& ops) {
    // Your implementation goes here
    printf("submit_ops_to_slave\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<SlaveOpsServerHandler> handler(new SlaveOpsServerHandler());
  shared_ptr<TProcessor> processor(new SlaveOpsServerProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
