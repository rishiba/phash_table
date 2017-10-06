#ifndef __SLAVELOCAL_H
#define __SLAVELOCAL_H

#include "MyMap.h"
#include "../gen-cpp/wal_types.h"

class SlaveLocal {

    private:
        MyMap *map;
        int insert_record(std::string key, std::string value);
        int search_record(std::string const key, std::string &value);

    protected:
        // function for getting all the values of the map.
    public:
    	SlaveLocal();
        int submit_ops(const SlaveOpsArguments &);
};

#endif
