#include "MyMap.h"
#include "wal_user.h"
#include <string>
#include <iostream>

int test_inserts_and_searches_positive (int count) {
	/* Function to test if we can find the inserted values or no. */
    MyMap *x = new MyMap();

    int i;
	std::string key, value;

    for (i = 0; i < count; i++) {
        key = "key" + std::to_string(i);
        value = "value" + std::to_string(i);
        int retval = x->insert_record(key, value);

        if (retval != SUCCESS) {
			std::cerr << "\nCould not add key " << key << " value: " << value << " to the map " << std::endl;
            return retval;
        } else {
			std::cerr <<"\nSuccessfully added the key in the map" << key << " value: " << value << " to the map " << std::endl;
		}
		
		std::string ret_string;
		retval = x->search_record(key, ret_string);

		if (retval == SUCCESS) {
			if (value == ret_string) {
				std::cerr <<"\nGot the value back correctly";
			} else {
				std::cerr <<"\nFunction returned SUCCESS but returned incorrect key";
				std::cerr <<"\nKey : " << key <<" Returned Value : " <<  ret_string << " Expected value " << value << std::endl;
				
				return -1;
			}
		}
    }

    return SUCCESS;
}


int test_inserts_and_searches_negative(int count) {
    MyMap *x = new MyMap();

    int i, retval;
	std::string key, value;

    for (i = 0; i < count; i++) {
        key = "key" + std::to_string(i);
        value = "value" + std::to_string(i);
        int retval = x->insert_record(key, value);

		
        if (retval != SUCCESS) {
			std::cerr << "\nCould not add key " << key << " value: " << value << " to the map " << std::endl;
            return retval;
        } else {
			std::cerr <<"\nSuccessfully added the key in the map" << key << " value: " << value << " to the map " << std::endl;
		}

	}
		std::string ret_string;

		key = "non-existent-key";
		retval = x->search_record(key, ret_string);

		if (retval == SUCCESS) {
			std::cerr <<"\nIncorrect return value, the key " << key << " was not added to the map";
			return -1;
		} else if (retval == ERR_KEY_NOT_FOUND) {
			std::cerr <<"\nCorrect return value";
		} else {
			std::cerr << "\nIncorrect return value";
		}
	
    return SUCCESS;
    }

 

int main () {
	int retval;
    if ((retval = test_inserts_and_searches_positive(10)) != SUCCESS) {
		std::cerr << "\nIncorrect";	
	} else {
		std::cerr << "\nCorrect";
	}
    if ((retval = test_inserts_and_searches_negative(10)) != SUCCESS) {
		
		std::cerr << "\nIncorrect";	
	} else {
		std::cerr << "\nCorrect";
	}
}
