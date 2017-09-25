#include "MyMap.h"
#include <string>
#include <iostream>
#include "wal_user.h"

int MyMap::insert_record(std::string key, std::string value) {
	mymap.insert(std::make_pair<std::string &, std::string &> (key, value));
	return 0;
}

int MyMap::delete_record(std::string key) {
	return 1;
}

int MyMap::update_record(std::string key, std::string value) {
	return 1;
}

int MyMap::search_record(std::string key, std::string& value) {

    std::unordered_map<std::string, std::string>::iterator it = mymap.find(key);

    if (it == mymap.end()) {
        std::cerr << "\nKey " << key << " not found in the map" << std::endl;
       
	return ERR_KEY_NOT_FOUND;
    } else {
        std::cerr <<"\nKey "<< key << " has the value as " << it->second << std::endl;
        value = it->second;
        return SUCCESS;
    }
    
    return ERR_INCORRECT_PLACE_TO_RETURN;
}
