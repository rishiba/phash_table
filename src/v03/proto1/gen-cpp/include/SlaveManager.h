#ifndef __SLAVEMANAGER_H
#define __SLAVEMANAGER_H
#include "Slave.h"
#include <cstdint>
#include <queue>
#include <unordered_map>
#include "../wal_types.h"

class SlaveManager:Slave {

    private:
        std::queue <std::int64_t> in_progress, done;
        std::unordered_map <std::int64_t, void *> seq_vs_ops;

        int process_in_progress_records();
        int process_done_records();
        // The handler for the SlaveClient.
    public:
        SlaveManager() {
            // Start the connection and wait for someone to join.
        }

        int submit_ops(SlaveOps *);
};

#endif
