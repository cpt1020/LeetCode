#include <iostream>
#include <vector>
using namespace std;

/*
g++ 1658.cpp -std=c++17 -o 1658 && ./1658
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum {0};
        for (auto it {nums.begin()}; it != nums.end(); ++it) {
            sum += *(it);
        }
        int target {sum - x};

        if (target < 0) {
            return -1;
        }
        else if (target == 0) {
            return nums.size();
        }

        int size {static_cast<int>(nums.size())};
        int min_op {INT_MAX};
        int cur_sum {0};
        int left_idx {0}, right_idx {0};

        while (right_idx < size) {
            cur_sum += nums.at(right_idx++);

            while (cur_sum > target && left_idx < size) {
                cur_sum -= nums.at(left_idx++);
            }

            if (cur_sum == target) {
                min_op = min(min_op, size - (right_idx - left_idx));
            }
        }

        return (min_op == INT_MAX) ? -1 : min_op;
    }
};

int main() {

    Solution sol;

    vector<int> nums {1,1,4,2,3};
    int x {5};
    // Output: 2
    cout << sol.minOperations(nums, x) << endl;

    nums = {5,6,7,8,9};
    x = 4;
    // Output: -1
    cout << sol.minOperations(nums, x) << endl;

    nums = {3,2,20,1,1,3};
    x = 10;
    // Output: 5
    cout << sol.minOperations(nums, x) << endl;

    return 0;
}