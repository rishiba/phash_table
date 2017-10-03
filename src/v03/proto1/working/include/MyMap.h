#ifndef __MYMAP_H
#define __MYMAP_H

#include <unordered_map>
#include <string>

class MyMap {
	std::unordered_map <std::string, std::string> mymap;
    public:
        MyMap() {
        std::unordered_map <std::string, std::string> mymap;
    }
    ~MyMap();


	int insert_record(std::string key, std::string value);
	int search_record(std::string key, std::string &retval);
	int delete_record(std::string key);
	int update_record(std::string key, std::string value);
    
};

#endif
