#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 76.cpp -std=c++17 -o 76 && ./76
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> tmap, have_map;
        for (auto c: t) {
            if (tmap.find(c) == tmap.end()) {
                tmap[c] = 1;
            }
            else {
                tmap[c] += 1;
            }
        }

        int have {0}, need {static_cast<int>(tmap.size())}, start {0}, min {INT_MAX};
        pair<int, int> ans;

        for (int end {0}; end < s.size(); ++end) {
            char c {s.at(end)};
            if (tmap.find(c) != tmap.end()) {
                have_map[c] += 1;
            }

            if (tmap.find(c) != tmap.end() && have_map[c] == tmap[c]) {
                have += 1;
            }

            while (have == need) {
                if (end - start + 1 < min) {
                    ans = {start, end};
                    min = (end - start + 1);
                }
                
                have_map[s.at(start)] -= 1;
                if (tmap.find(s.at(start)) != tmap.end() && have_map[s.at(start)] < tmap[s.at(start)]) {
                    have -= 1;
                }
                start += 1;
            }
        }

        if (min != INT_MAX) {
            return s.substr(ans.first, ans.second - ans.first + 1);
        }
        else {
            return "";
        }
    }
};

int main() {

    Solution sol;
    string s {"ADOBECODEBANC"};
    string t {"ABC"};
    cout << sol.minWindow(s, t) << endl;

    return 0;
}