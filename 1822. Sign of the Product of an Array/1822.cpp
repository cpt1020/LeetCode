#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1822.cpp -std=c++17 -o 1822 && ./1822
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negNum {1};
        for (const auto& num: nums) {
            if (num == 0) {
                return 0;
            }
            else if (num < 0) {
                negNum *= -1;
            }
        }

        return negNum;
    }
};

int main() {

    Solution sol;

    vector<int> nums {-1,-2,-3,-4,3,2,1};
    // Output: 1
    cout << sol.arraySign(nums) << endl;

    nums = {1,5,0,2,-3};
    // Output: 0
    cout << sol.arraySign(nums) << endl;

    nums = {-1,1,-1,1,-1};
    // Output: -1
    cout << sol.arraySign(nums) << endl;

    return 0;
}