#include "SlaveLocal.h"
#include <string>
#include "wal_types.h"
#include "ops.h"
#include "MyMap.h"

SlaveLocal::SlaveLocal() {
        map = new MyMap();
}

int SlaveLocal::insert_record(std::string key, std::string value) {
    return map->insert_record(key, value);
}

int SlaveLocal::submit_ops(SlaveOps &ops) {
	int optype = ops.op_type;

	switch (optype) {
		case OP_INSERT:
			return this->insert_record(ops.key, ops.value);
			break;
		
		case OP_SEARCH:
			break;

		case OP_UPDATE:
			break;
		
		case OP_DELETE:
			break;
			
		default:
			return -1;
	}
}
