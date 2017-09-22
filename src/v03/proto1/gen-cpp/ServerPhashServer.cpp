// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <iostream>
#include <string>
#include <unordered_map>

#include "ReplicatedMap.h"
#include "PhashServer.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include "Map.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace std;
using boost::shared_ptr;


class PhashServerHandler : virtual public PhashServerIf {
    private:
        void fill_retval(ClientOpsRetval& _return, int errNo, string errMsg, string key);

        void insert_ops(ClientOpsRetval& _return, const ClientOps& ops) ;

        void process_ops(ClientOpsRetval& _return, const ClientOps& ops);

        ReplicatedMap *mymap;

    public:
        PhashServerHandler() {
            // Your initialization goes here
            mymap = new ReplicatedMap();
        }

        void ping(Ping_ACK& _return) {
            // Your implementation goes here
            printf("ping\n");
        }

        void submit_ops(ClientOpsRetval& _return, const ClientOps& ops) {
            // Your implementation goes here
            printf("submit_ops\n");
            ops.printTo(cout);
            return process_ops(_return, ops);
        }
};

void PhashServerHandler::insert_ops(ClientOpsRetval& retval, const ClientOps& ops) {

    string key = ops.key, value = ops.value, errMsg="";
    int errNo = mymap->insert_record(key, value, errMsg);

    retval.key = key;
    if (errNo != 0) {
        retval.errNo = errNo;
        retval.value = errMsg;
    } else {
        retval.value ="";
    }
}

void PhashServerHandler::process_ops(ClientOpsRetval& retval, const ClientOps& ops) {
    switch (ops.op_type) {
        case MAP_INSERT:
            insert_ops(retval, ops);
            break;
        case MAP_DELETE:

        default:
            cerr << "Incorrect Operation";
    }
}

int main(int argc, char **argv) {
    int port = 9090;
    boost::shared_ptr<PhashServerHandler> handler(new PhashServerHandler());
    boost::shared_ptr<TProcessor> processor(new PhashServerProcessor(handler));
    boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    return 0;
}
