#include <iostream>
#include <vector>
using namespace std;

/*
g++ 81.cpp -std=c++17 -o 81 && ./81
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        while (nums.size() > 1 && nums.back() == nums.at(0)) {
            nums.pop_back();
        }

        int left {0};
        int right = nums.size() - 1;
        int middle {0};

        while (left <= right) {
            middle = (left + right)/2;

            if (nums.at(middle) == target) {
                return true;
            }

            if ((target >= nums.at(0)) == (nums.at(middle) >= nums.at(0))) {
                if (nums.at(middle) < target) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
            else if (target >= nums.at(0)) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return false;
    }
};

int main() {

    Solution sol;

    vector<int> nums {2,5,6,0,0,1,2};
    int target {0};
    // Output: true
    cout << boolalpha << sol.search(nums, target) << endl;

    target = 3;
    cout << boolalpha << sol.search(nums, target) << endl;

    return 0;
}