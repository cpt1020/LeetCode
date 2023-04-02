#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
g++ 49.cpp -std=c++17 -o 49
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.size() == 1) {
        return {{strs}};
    }

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umap;

    for (int i {0}; i < strs.size(); ++i) {
        string str {strs.at(i)};

        // use sorted string as key
        // unsorted string as value
        sort(str.begin(), str.end());
        if (umap.find(str) == umap.end()) {
            umap[str] = {strs.at(i)};
        }
        else {
            umap[str].push_back(strs.at(i));
        }
    }

    for (auto& key: umap) {
        vector<string> tmp;
        for (auto& str: key.second) {
            tmp.push_back(str);
        }
        ans.push_back(tmp);
    }

    return ans;
}

int main() {

    vector<string> strs {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans {groupAnagrams(strs)};
    
    for (auto & vec: ans) {
        for (auto & str: vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}