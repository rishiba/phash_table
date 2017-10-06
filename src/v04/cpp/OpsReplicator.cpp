#include "OpsReplicator.h"
#include "SlaveLocal.h"
#include "wal_types.h"
#include "ops.h"
#include "wal_user.h"
#include <string>
#include "wal_constants.h"
#include <iostream>
#include "SlaveManager.h"

OpsReplicator::OpsReplicator() {
    localSlave = new SlaveLocal();
	sequence_number = 0;
	slaves = new std::vector<SlaveManager *>;
    slaves->push_back(new SlaveManager(9050, "localhost"));
}

long OpsReplicator::get_next_seq_num(void) {
	return ++sequence_number;
}

void OpsReplicator::push_into_slaves(SlaveOpsArguments *ops) {
	int i = 0;
    for (auto slave = slaves->begin(); slave != slaves->end(); slave++, i++) {
        std::cerr <<"\nPassing ops to " << i <<std::endl;

        (*slave)->submit_ops(ops);
    }
}

int OpsReplicator::insert_record(std::string key, std::string value) {
    int retval;
    SlaveOpsArguments *ops = new SlaveOpsArguments();
    ops->op_type = OP_INSERT;
    ops->key = key;
    ops->value = value;
    ops->seq_number = this->get_next_seq_num();

    SlaveOpsArguments &ref_ops = *ops;
    retval = localSlave->submit_ops(ref_ops);

    if (retval != SUCCESS) {
        // Do not add this to the other remote threads.
        return retval;
    } else {
        // Add into other slaves queues.
        push_into_slaves(ops);
        return retval;
    }
	return ERR_INCORRECT_PLACE_TO_RETURN;
}

int OpsReplicator::update_record(std::string key) {
	return ERR_INCORRECT_PLACE_TO_RETURN;
}
int OpsReplicator::delete_record(std::string key) {
	return ERR_INCORRECT_PLACE_TO_RETURN;
}
int OpsReplicator::resync_slave(void) {
	return ERR_INCORRECT_PLACE_TO_RETURN;
}
int OpsReplicator::search_record(std::string const key, std::string &value) {

    long seq_number = this->get_next_seq_num();
    int retval;
    SlaveOpsArguments *ops = new SlaveOpsArguments();
    ops->op_type = OP_SEARCH;
    ops->key = key;
    ops->seq_number = seq_number;

    SlaveOpsArguments &ref_ops = *ops;
    retval = localSlave->submit_ops(ref_ops);

    if (retval != SUCCESS) {
        // Do not add this to the other remote threads.
        value = ops->value;
		return retval;
    }
	return ERR_INCORRECT_PLACE_TO_RETURN;
}
