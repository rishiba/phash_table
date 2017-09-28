#include "OpsReplicator.h"
#include "SlaveLocal.h"
#include "wal_types.h"
#include "ops.h"
#include "wal_user.h"
#include <string>

OpsReplicator::OpsReplicator() {
    localSlave = new SlaveLocal();
	sequence_number = 0;
}
long OpsReplicator::get_next_seq_num(void) {
	return ++sequence_number;
}

int OpsReplicator::insert_record(std::string key, std::string value) {
    long seq_number = this->get_next_seq_num();
    int retval;
    SlaveOps ops = SlaveOps();
    ops.op_type = OP_INSERT;
    ops.key = key;
    ops.value = value;
    ops.seq_number = seq_number;

    retval = localSlave->submit_ops(ops);

    if (retval != SUCCESS) {
        // Do not add this to the other remote threads.
        return retval;
    }
}

int OpsReplicator::update_record(std::string key) {
}
int OpsReplicator::delete_record(std::string key) {
}
int OpsReplicator::resync_slave(void) {
}
int OpsReplicator::search_record(std::string const key, std::string &value) {

    long seq_number = this->get_next_seq_num();
    int retval;
    SlaveOps ops = SlaveOps();
    ops.op_type = OP_SEARCH;
    ops.key = key;
    ops.seq_number = seq_number;

    retval = localSlave->submit_ops(ops);

    if (retval != SUCCESS) {
        // Do not add this to the other remote threads.
        value = ops.value;
		return retval;
    }
}
