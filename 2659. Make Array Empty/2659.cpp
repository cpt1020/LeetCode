#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*
g++ 2659.cpp -std=c++17 -o 2659 && ./2659
*/

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {        
        long long res {1};
        int n = nums.size();

        vector<pair<int, int>> vec;
        for (int i {0}; i < n; ++i) {
            vec.push_back({nums.at(i), i});
        }

        sort(vec.begin(), vec.end());

        for (int i = n - 2; i >= 0; --i) {
            if (vec.at(i).second > vec.at(i+1).second) {
                res += (n-i);
            }
            else {
                res += 1;
            }
        }
        return res;
    }
};

int main() {

    Solution sol;

    vector<int> nums {3,4,-1};
    // Output: 5
    cout << sol.countOperationsToEmptyArray(nums) << endl;

    nums = {1,2,4,3};
    // Output: 5
    cout << sol.countOperationsToEmptyArray(nums) << endl;

    nums = {1,2,3};
    // Output: 3
    cout << sol.countOperationsToEmptyArray(nums) << endl;

    return 0;
}