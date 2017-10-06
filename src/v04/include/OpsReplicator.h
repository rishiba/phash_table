#ifndef __OPSREPLICATOR_H
#define __OPSREPLICATOR_H
#include "SlaveLocal.h"
#include "SlaveManager.h"
#include <string>
#include <vector>

class OpsReplicator {
    private:
        // std::map <int64_t, > seq_ops_map;
        int add_to_slave_quque();
        // std::vector <Slave> SlaveManager;
        SlaveLocal *localSlave;
        std::vector <SlaveManager *> *slaves;

        long sequence_number;
        long get_next_seq_num(void);
        void push_into_slaves(SlaveOpsArguments *ops);
    public:
        OpsReplicator();
        int insert_record(std::string const key, std::string const value);
        int update_record(std::string const key);
        int delete_record(std::string const key);
        int search_record(std::string const key, std::string &value);
        int resync_slave(void);
};
#endif
