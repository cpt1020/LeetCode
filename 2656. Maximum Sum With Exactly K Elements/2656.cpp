#include <vector>
#include <iostream>
using namespace std;

/*
g++ 2656.cpp -std=c++17 -o 2656 && ./2656
*/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int res {0};
        for (int i {0}; i < k; ++i) {
            auto it = max_element(nums.begin(), nums.end());
            res += *it;
            *it += 1;
        }
        return res;
    }
};

int main() {

    Solution sol;

    vector<int> nums {1,2,3,4,5};
    int k {3};
    // ans: 18
    cout << sol.maximizeSum(nums, k) << endl;

    nums = {5,5,5};
    k = 2;
    // ans: 11
    cout << sol.maximizeSum(nums, k) << endl;

    return 0;
}