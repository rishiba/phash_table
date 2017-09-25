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

	int insert_record(std::string key, std::string value);
	std::string search_record(std::string key);
	int delete_record(std::string key);
	int update_record(std::string key, std::string value);
};

#endif
