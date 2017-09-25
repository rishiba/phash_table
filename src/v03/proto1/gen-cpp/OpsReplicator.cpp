#include "OpsReplicator.h"
#include "SlaveLocal.h"

OpsReplicator::OpsReplicator() {
    localSlave = new SlaveLocal();
}

int OpsReplicator::insert_record(string key, string value) {
    long seq_num = get_next_seq_num();
}
int OpsReplicator::update_record(string key) {
}
int OpsReplicator::delete_record(string key) {
}
int OpsReplicator::resync_slave(void) {
}
string search_record(string key);
