#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string>> umap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        umap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (umap.find(key) == umap.end()) {
            return "";
        }

        if (umap[key].find(timestamp) != umap[key].end()) {
            return umap[key][timestamp];
        }

        auto it = umap[key].upper_bound(timestamp);
        if (it == umap[key].begin()) {
            return "";
        }
        else {
            return (--it)->second;
        }
    }
};


int main() {

    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar" ,1);
    cout << obj->get("foo", 1) << endl;
    cout << obj->get("foo", 3) << endl;
    obj->set("foo", "bar2" ,4);
    cout << obj->get("foo", 4) << endl;
    cout << obj->get("foo", 5) << endl;

    return 0;
}