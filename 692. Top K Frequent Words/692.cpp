#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

/*
g++ 692.cpp -std=c++17 -o 692 && ./692
*/

bool rule(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for (auto str: words) {
            umap[str] += 1;
        }

        vector<pair<string, int>> tmp;
        for (auto key: umap) {
            tmp.push_back({key.first, key.second});
        }

        // using lambda expression for sorting
        // sort(tmp.begin(), tmp.end(), [](pair<string,int> a, pair<string, int> b){
        //     if (a.second == b.second) {
        //         return a.first < b.first;
        //     }
        //     else {
        //         return a.second > b.second;
        //     }
        // });

        // self-defined function for sorting
        sort(tmp.begin(), tmp.end(), rule);

        vector<string> ans;
        for (int i {0}; i < k; ++i) {
            ans.push_back(tmp.at(i).first);
        }
        return ans;
    }
};

int main() {

    Solution sol;

    vector<string> words {"the","day","is","sunny","the","the","the","sunny","is","is"};
    vector<string> ans {sol.topKFrequent(words, 4)};
    for (auto str: ans) {
        cout << str << " ";
    }
    cout << endl;

    words = {"i","love","leetcode","i","love","coding"};
    ans = sol.topKFrequent(words, 2);
    for (auto str: ans) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}