#include "MyMap.h"
#include <string>

int test_inserts (int count) {
    MyMap *x = new MyMap();
    
    int i;
    
    for (i = 0; i < count; i++) {   
        std::string key = "key" + std::to_string(i);
        std::string value = "value" + std::to_string(i);
        int retval = x->insert_record(key, value);
        
        if (retval) {
            return retval;
        }
           
    }
    return 0;
}

int main () {
    retval = test_inserts(10);

}
