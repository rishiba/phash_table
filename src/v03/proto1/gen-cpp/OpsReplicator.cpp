#include "OpsReplicator.h"
#include "SlaveLocal.h"
#include "wal_types.h"
#include "ops.h"
#include "wal_user.h"

OpsReplicator::OpsReplicator() {
    localSlave = new SlaveLocal();
}

int OpsReplicator::insert_record(string key, string value) {
    long seq_num = get_next_seq_num();
    int retval;
    SlaveOps ops = SlaveOps();
    ops.op_type = OP_INSERT;
    ops.key = key;
    ops.value = value;
    ops.seq_num = seq_num;

    retval = localSlave.submit_ops(ops);

    if (retval != SUCCESS) {
        // Do not add this to the other remote threads.
        return retval;
    }
}

int OpsReplicator::update_record(string key) {
}
int OpsReplicator::delete_record(string key) {
}
int OpsReplicator::resync_slave(void) {
}
string search_record(string key);
