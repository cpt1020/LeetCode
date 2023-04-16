#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 2640.cpp ../utils.cpp -std=c++17 -o 2640 && ./2640
*/

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {        
        long long max_arr = nums.at(0);
        long long prefix = 2LL*nums.at(0);
        vector<long long> ans (nums.size());
        ans.at(0) = prefix;

        for (int i {1}; i < nums.size(); ++i) {
            max_arr = max((long long)nums.at(i), max_arr);
            prefix = nums.at(i) + max_arr;
            ans.at(i) = ans.at(i-1) + prefix;
        }

        return ans;
    }
};

int main() {

    Solution sol;
    vector<int> nums {2,3,7,5,10};
    printVector(sol.findPrefixScore(nums));
    nums = {1,1,2,4,8,16};
    printVector(sol.findPrefixScore(nums));

    return 0;
}