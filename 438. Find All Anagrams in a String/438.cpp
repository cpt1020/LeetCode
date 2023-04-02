#include <iostream>
#include <vector>
#include <string>
#include "../utils.h"
using namespace std;

/*
g++ 438.cpp ../utils.cpp -std=c++17 -o 438 && 438
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        vector<int> ans;
        int p_size {static_cast<int>(p.size())};
        int s_size {static_cast<int>(s.size())};
        vector<int> freq (26, 0);
        vector<int> window (26, 0);

        for (int i {0}; i < p_size; ++i) {
            freq.at(p.at(i) - 'a') += 1;
            window.at(s.at(i) - 'a') += 1;
        }

        if (freq == window) {
            ans.push_back(0);
        }

        for (int i {p_size}; i < s_size; ++i) {
            window.at(s.at(i) - 'a') += 1;
            window.at(s.at(i - p_size) - 'a') -= 1;

            if (freq == window) {
                ans.push_back(i - p_size + 1);
            }
        }

        return ans;
    }
};

int main() {
    
    Solution sol;
    string s {"abab"};
    string p {"ab"};
    printVector(sol.findAnagrams(s, p));

    return 0;
}