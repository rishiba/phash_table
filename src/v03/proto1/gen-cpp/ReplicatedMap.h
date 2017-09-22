class ReplicatedMap {
    private:
        unordered_map <string, string> *mymap;
        int count;

    public:
        ReplicatedMap();
        int insert_record(string key, string value, string errMsg);
        string search_record(string key, string value);
        int delete_record(string key);
        int update_record(string key, string value);
};
