#include "Slave.h"

class SlaveManager:Slave {
    
    private:
        std::queue in_progress, done;
        std::map <int, reference> seq_num to SlaveOps;
        
        int process_in_progress_records();
        int process_done_records();
    public:
        SlaveManager() {
            // Start the connection and wait for someone to join.
        }
        
        virtual int submit_ops(SlaveOps);

}

int SlaveManager::process_in_progress_records() {
    /* Function to read the in_progress queue and then send the records to the connected SlaveClient . */
}

int SlaveManager::process_done_records() {
    /* Function to read the done queue and reduce the reference count from the seq_ops_map */
}
