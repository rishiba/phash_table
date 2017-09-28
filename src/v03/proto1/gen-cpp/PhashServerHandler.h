
#include "PhashServer.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "OpsReplicator.h"
#include "ops.h"
#include "wal_user.h"
class PhashServerHandler : virtual public PhashServerIf {
	private:
		OpsReplicator *replicator;

	public:
		PhashServerHandler();
		void ping(Ping_ACK& _return);
		void submit_ops(ClientOpsRetval& _return, const ClientOps& ops);
};
