template <class K, class V>
class Phash {

private:
    std::map mymap <K, V>;

    int insert(K &key, V &value) {
    }

    V search(K &key) {
    }

    int delete_key(K &key) {
    }

    int update(K &key, Value &v) {
    }
    

public:
    Phash() {
        mymap = std::map<K, V>;
    }
    int do_ops(Ops &op) {
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
}
