#ifndef __SLAVEMANAGER_H
#define __SLAVEMANAGER_H
#include <cstdint>
#include <queue>
#include <unordered_map>
#include "wal_types.h"
#include <SlaveOpsServer.h>

class SlaveManager {

    private:
        std::queue <std::int64_t> in_progress, done;
        std::unordered_map <std::int64_t, void *> seq_vs_ops;

	SlaveOpsServerClient *client;
        int process_in_progress_records();
        int process_done_records();
        // The handler for the SlaveClient.
    public:
        SlaveManager(int port, std::string host);

        int submit_ops(SlaveOpsArguments *ops);
};

#endif
