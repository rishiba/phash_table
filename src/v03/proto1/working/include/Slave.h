#ifndef __SLAVE_H
#define __SLAVE_H
#include "../gen-cpp/wal_types.h"
class Slave {
    public:
        Slave();
        int submit_ops(SlaveOps &);
};

#endif
