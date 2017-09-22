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

std::string MyMap::search_record(std::string key) {
	return "ERROR";
}



