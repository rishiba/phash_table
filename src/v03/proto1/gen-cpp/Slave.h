#ifndef __SLAVE_H
#define __SLAVE_H
#include "wal_types.h"
class Slave {
    public:
        Slave() {
        }

        virtual int submit_ops(SlaveOps &);
        
};

#endif
