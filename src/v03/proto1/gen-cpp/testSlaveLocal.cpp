
#include "MyMap.h"
#include "SlaveLocal.h"
#include "wal_types.h"
#include "ops.h"
#include <string>


int test_inserts (int count) {
    SlaveLocal *x = new SlaveLocal();

    int i;

    for (i = 0; i < count; i++) {
        SlaveOps ops = SlaveOps();
        ops.seq_number = i;
        ops.op_type = OP_INSERT; 
        ops.key = "key" + std::to_string(i);
        ops.value = "value" + std::to_string(i);
        int retval = x->submit_ops(ops);

        if (retval) {
            return retval;
        }

    }
    return 0;
}
int main () {

    int retval = test_inserts(10);

}
