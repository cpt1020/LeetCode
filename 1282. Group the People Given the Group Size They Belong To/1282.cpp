#include <iostream>
#include <unordered_map>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 1282.cpp ../utils.cpp -std=c++17 -o 1282 && ./1282
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> res;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes.at(i)].push_back(i);
            if (mp[groupSizes.at(i)].size() == groupSizes.at(i)) {
                res.push_back(mp[groupSizes.at(i)]);
                mp.erase(groupSizes.at(i));
            }
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<int> groupSizes {3,3,3,3,3,1,3};
    print2dVector<int>(sol.groupThePeople(groupSizes));

    groupSizes = {2,1,3,3,3,2};
    print2dVector<int>(sol.groupThePeople(groupSizes));

    return 0;
}