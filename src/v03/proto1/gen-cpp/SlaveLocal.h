#ifndef __SLAVELOCAL_H
#define __SLAVELOCAL_H

#include "Slave.h"
#include "MyMap.h"
#include "wal_types.h"

class SlaveLocal:Slave {

    private:
        MyMap *map;

    protected:
        // function for getting all the values of the map.
        int insert_record(std::string key, std::string value);
    public:
    	SlaveLocal();
        int submit_ops(SlaveOps &);
};

#endif
