#include "Ops.h"

int Phash::do_ops(Ops &ob) {
        int op_type = op.get_op_type();

        switch(op_type) {
            case OP_INSERT:

                break;
            case OP_UPDATE:
                break;

            case OP_SEARCH:
                break;

            case OP_DELETE:
                break;

            default:
                throw("Incorrect Operation type");
        }
}


