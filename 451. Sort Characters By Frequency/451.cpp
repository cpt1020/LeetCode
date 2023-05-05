#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 451.cpp -std=c++17 -o 451 && ./451
*/

class Solution {
public:
    string frequencySort01(string s) {
        unordered_map<char, int> umap;
        for (auto& ch: s) {
            umap[ch] += 1;
        }

        sort(s.begin(), s.end(), [&](char& a, char& b){
            if (umap[a] != umap[b]) {
                return umap[a] > umap[b];
            }
            else {
                return a < b;
            }
        });
        
        return s;
    }

    string frequencySort02(string s) {
        unordered_map<char, int> umap;
        for (auto& ch: s) {
            umap[ch] += 1;
        }

        vector<pair<char, int>> tmp;
        for (auto& ch: s) {
            tmp.push_back({ch, umap[ch]});
        }

        sort(tmp.begin(), tmp.end(), [](pair<char, int>& a, pair<char, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            else {
                return a.second > b.second;
            }
        });

        string ans {""};
        for (auto& p: tmp) {
            ans += p.first;
        }
        return ans;
    }
};

int main() {

    Solution sol;

    string s {"tree"};
    // Output: "eert"
    cout << sol.frequencySort01(s) << endl;
    cout << sol.frequencySort02(s) << endl;

    s = "cccaaa";
    // Output: "aaaccc"
    cout << sol.frequencySort01(s) << endl;
    cout << sol.frequencySort02(s) << endl;

    s = "Aabb";
    // Output: "bbAa"
    cout << sol.frequencySort01(s) << endl;
    cout << sol.frequencySort02(s) << endl;

    return 0;
}