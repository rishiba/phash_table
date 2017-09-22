/** Class for creating a Operation Object. This object will have the type of
operation like insert/delete/search/update and the key and value associated
with it.
*/


class Ops {

private:
	int op_type;
	std::string key, value;

protected:
	std::string getKey() {
		return key;
	}

	std::string getValue() {
		return value;
	}

	int get_op_type() {
		return op_type;
	}
public:
	Ops(unsigned int op_type, std::string key, std::string val) {
		if (op_type != OP_INSERT || op_type != OP_UPDATE) {
			throw ("Incorrect type of operation passed");
		}
	}

	Ops(unsigned int op_type, std::string &key) {
		if (op_type != OP_DELETE || op_type != OP_SEARCH) {
			throw ("Incorrect type of operation passed");
		}
	}

	/** Function to return the address of the object.
	
	This also increases the reference count by 1.
	*/
	class Ops & get_ref(void) {
	
	}

	/** Function to put the reference back. This also decreaes the reference count by 1. If the reference count becomes 0 the desctructor is called. */
	class Ops &put_ref(void) {
	}
}
