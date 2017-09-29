#include <iostream>
#include <unordered_map>

class ReplicatedMap {
    private:
        std::unordered_map <std::string, std::string> *mymap;
        int count;

    public:
        ReplicatedMap();
        int insert_record(std::string key, std::string value, std::string errMsg);
        std::string search_record(std::string key, std::string value);
        int delete_record(std::string key);
        int update_record(std::string key, std::string value);
};
