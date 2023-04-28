#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 2433.cpp ../utils.cpp -std=c++17 -o 2433 && ./2433
*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if (pref.size() == 1) {
            return pref;
        }

        vector<int> ans {pref.at(0)};

        for (int i {1}; i < pref.size(); ++i) {
            ans.push_back(pref.at(i-1) ^ pref.at(i));
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> pref {5,2,0,3,1};
    // Output: [5,7,2,3,2]
    printVector<int>(sol.findArray(pref));

    pref = {13};
    // Output: [13]
    printVector<int>(sol.findArray(pref));
    
    return 0;
}