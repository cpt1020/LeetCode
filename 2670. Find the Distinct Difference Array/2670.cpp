#include <vector>
#include <unordered_set>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 2670.cpp ../utils.cpp -std=c++17 -o 2670 && ./2670
*/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> prefix;
        vector<int> suffix;
        
        unordered_set<int> distinctPrefix;
        for (int i {0}; i < nums.size(); ++i) {
            distinctPrefix.insert(nums.at(i));
            prefix.push_back(distinctPrefix.size());
        }
        
        unordered_set<int> distinctSuffix;
        for (int i = nums.size()-1; i >= 0; --i) {
            distinctSuffix.insert(nums.at(i));
            suffix.push_back(distinctSuffix.size());
        }
        
        reverse(suffix.begin(), suffix.end());
        
        for (int i {0}; i < nums.size(); ++i) {
            if (i + 1 == nums.size()) {
                ans.push_back(prefix.at(i));
            }
            else {
                ans.push_back(prefix.at(i) - suffix.at(i+1));
            }
        }
        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums {1,2,3,4,5};
    // Output: [-3,-1,1,3,5]
    printVector<int>(sol.distinctDifferenceArray(nums));

    nums = {3,2,3,4,2};
    // Output: [-2,-1,0,2,3]
    printVector<int>(sol.distinctDifferenceArray(nums));

    return 0;
}