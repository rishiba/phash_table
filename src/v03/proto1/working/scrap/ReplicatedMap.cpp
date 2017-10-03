ReplicatedMap::ReplicatedMap() {
	mymap = new (unordered_map <string, string>);
	count = 0;
}

int ReplicatedMap::insert_record(string key, string value, string errMsg) {
	// mymap->insert(make_pair<string, string> (&key, &value));
	string key1(key);
	string value1(value);
	mymap->insert(make_pair<string &, string&> (key1, value1));
	++count;

	if (count%5 == 0) {
		for (auto &x: *mymap) {
			cerr << "Key: " << x.first << " Value: " << x.second << endl;
		}
	}
	return 0;
}

string ReplicatedMap::search_record(string key, string value) {
	return "";
}

int ReplicatedMap::delete_record(string key) {
	return 0;
}

int ReplicatedMap::update_record(string key, string value) {
	return 0;
}
