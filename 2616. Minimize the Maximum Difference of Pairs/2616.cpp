#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int left {0};   // min difference
        int right {nums.at(nums.size() - 1) - nums.at(0)};   // the maximum difference
        int middle {0};

        while (left < right) {
            middle = (left + right)/2;

            int count {0}; // number of pair that has diff less than maximum difference
            
            for (int i {0}; i < nums.size(); ++i) {
                if (i + 1 < nums.size() && nums.at(i+1) - nums.at(i) <= middle) {
                    count += 1;
                    i += 1;
                }
            }

            if (count >= p) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }
};

int main() {

    Solution sol;

    vector<int> nums {10,1,2,7,1,3};
    int p {2};
    // Output: 1
    cout << sol.minimizeMax(nums, p) << endl;

    nums = {4,2,1,2};
    p = 1;
    // Output: 0
    cout << sol.minimizeMax(nums, p) << endl;

    nums = {8,9,1,5,4,3,6,4,3,7};
    p = 4;
    // Output: 1
    cout << sol.minimizeMax(nums, p) << endl;

    nums = {3,4,2,3,2,1,2};
    p = 3;
    // Output: 1
    cout << sol.minimizeMax(nums, p) << endl;

    return 0;
}