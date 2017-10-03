#ifndef __OPSREPLICATOR_H
#define __OPSREPLICATOR_H
#include "SlaveLocal.h"
// #include "SlaveManager.h"
#include <string>

class OpsReplicator {
    private:
//        std::map <int64_t, shared_ptr> seq_ops_map;
  //      long get_next_seq_num();
    //    int add_to_slave_quque();
      //  std::vector <Slave> SlaveManager;
        SlaveLocal *localSlave;
//        std::vector <SlaveManager *> *slaves;
        
        long sequence_number;
    private:
        long get_next_seq_num(void);
        void push_into_slaves(SlaveOps *ops);
    public:
        OpsReplicator();
        int insert_record(std::string const key, std::string const value);
        int update_record(std::string const key);
        int delete_record(std::string const key);
        int search_record(std::string const key, std::string &value);
        int resync_slave(void);
};
#endif
