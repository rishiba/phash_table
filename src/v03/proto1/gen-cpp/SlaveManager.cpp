#include "wal_types.h"
#include "SlaveManager.h"
#include <cstdint>
#include <iostream>
#include "wal_user.h"

void print_queue(std::queue <std::int64_t> q) {
}

void print_map(std::unordered_map<std::int64_t, void *> mymap) {
	for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for ( auto local_it = mymap.cbegin(i); local_it!= mymap.cend(i); ++local_it )
			std::cout << " " << local_it->first << ":" << local_it->second;
		std::cout << std::endl;
	}
}

int SlaveManager::submit_ops(SlaveOps *ops) {
    // Add the ops to the queue and the map. Then signal the process_in_progress_records to wake up.

    // Take the lock on the in_progress queue.
    // Take the lock on the condition variable mutex.
    // Add the ops into the queue.
    // Release the lock on the queue and signal the condition variable.
	std::cerr <<"\nAdding to the quque";
	in_progress.push(ops->seq_number);

	auto pair = std::make_pair (ops->seq_number, (void *) ops);

	std::cerr <<"\nAdding to the map";
	seq_vs_ops.insert(pair);
	print_map(seq_vs_ops);

    return SUCCESS;
}

int SlaveManager::process_in_progress_records(void) {
    /* Function to read the in_progress queue and then send the records to the connected SlaveClient . */
    return ERR_INCORRECT_PLACE_TO_RETURN;
}

int SlaveManager::process_done_records(void) {
    /* Function to read the done queue and reduce the reference count from the seq_ops_map */
    return ERR_INCORRECT_PLACE_TO_RETURN;
}

