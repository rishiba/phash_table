#include "SlaveLocal.h"
#include "SlaveManager.h"

class OpsReplicator {
    private:
        std::map <int64_t, shared_ptr> seq_ops_map;
        long get_next_seq_num();
        int add_to_slave_quque();
        std::vector <Slave> SlaveManager;
        Slave local = new SlaveLocal();
        
    public:
        int insert_record(string key, string value);
        int update_record(string key);
        int delete_record(string key);
        string search_record(string key);
        int resync_slave(void);
    
}

int OpsReplicator::insert_record(string key, string value) {
}
int OpsReplicator::update_record(string key) {
}
int OpsReplicator::delete_record(string key) {
}
int OpsReplicator::resync_slave(void) {
}
string search_record(string key);
