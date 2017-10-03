#include "SlaveLocal.h"
#include <string>
#include "wal_types.h"
#include "ops.h"
#include "MyMap.h"
#include "wal_user.h"
#include <iostream>

SlaveLocal::SlaveLocal() {
        map = new MyMap();
}

int SlaveLocal::insert_record(std::string key, std::string value) {
	std::cerr << "\nInserting record " << __FILE__ << " " <<__LINE__ << std::endl;
	
	int retval = map->insert_record(key, value);

	std::cerr << "\nretval is " << retval;
	if (retval != 0) {
		std::cerr <<"\nError inserting record at " << __FILE__ << " " <<__LINE__ << std::endl;
	} else {
		return retval;
	}

	return ERR_INCORRECT_PLACE_TO_RETURN;
}

int SlaveLocal::search_record(std::string const key, std::string &value) {
    return map->search_record(key, value);
}

int SlaveLocal::submit_ops(SlaveOpsArguments *ops) {
	int optype = ops->op_type;
    std::cerr << "\nPerfroming Operation opType: " << ops->op_type << " with seq number as " << ops->seq_number << std::endl;

	switch (optype) {
		case OP_INSERT:
			return this->insert_record(ops->key, ops->value);
			break;
		
		case OP_SEARCH:
            return this->search_record(ops->key, ops->value);
			break;

		case OP_UPDATE:
			break;
		
		case OP_DELETE:
			break;
			
		default:
			return -1;
	}
	return ERR_INCORRECT_PLACE_TO_RETURN;
}
