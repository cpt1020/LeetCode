#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.h"
using namespace std;

/*
g++ 189.cpp ../utils.cpp -std=c++17 -o 189 && ./189
*/

class Solution {
public:

    void rotate01(vector<int>& nums, int k) {
        int size = nums.size();

        if (size < k) {
            k = k % size;
        }
        
        vector<int> ans;
        for (int i {size - k}; i < size; ++i) {
            ans.push_back(nums.at(i));
        }
        for (int i {0}; i < (size - k); ++i) {
            ans.push_back(nums.at(i));
        }
        nums = ans;
    }

    void rotate02(vector<int>& nums, int k) {
        int size = nums.size();
        if (size < k) {
            k = k % size;
        }
        auto it = nums.begin();
        reverse(it, it + (size - k));
        reverse(it + (size - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {

    Solution sol;

    // test case 01
    vector<int> nums {1,2,3,4,5,6,7};
    int k {3};
    sol.rotate01(nums, k);
    printVector<int>(nums);

    nums = {1,2,3,4,5,6,7};
    sol.rotate02(nums, k);
    printVector<int>(nums);

    // test case 02
    nums = {-1,-100,3,99};
    k = 2;
    sol.rotate01(nums, k);
    printVector<int>(nums);

    nums = {-1,-100,3,99};
    sol.rotate02(nums, k);
    printVector<int>(nums);

    return 0;
}