#include "Slave.h"

class SlaveLocal:Slave {
    protected:
        // function for getting all the values of the map.
    public:
        virtual int submit_ops(SlaveOps);
}
