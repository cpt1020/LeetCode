#include <unordered_set>
#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 2215.cpp ../utils.cpp -std=c++17 -o 2215 && ./2215
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1, num2;
        for (auto& num: nums1) {
            num1.insert(num);
        }
        for (auto& num: nums2) {
            num2.insert(num);
        }

        vector<vector<int>> ans (2);
        for (auto& num: num1) {
            if (num2.find(num) == num2.end()) {
                ans.at(0).push_back(num);
            }
        }

        for (auto& num: num2) {
            if (num1.find(num) == num1.end()) {
                ans.at(1).push_back(num);
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums1 {1,2,3};
    vector<int> nums2 {2,4,6};
    // Output: [[1,3],[4,6]]
    print2dVector<int>(sol.findDifference(nums1, nums2));

    nums1 = {1,2,3,3};
    nums2 = {1,1,2,2};
    // Output: [[3],[]]
    print2dVector<int>(sol.findDifference(nums1, nums2));

    return 0;
}