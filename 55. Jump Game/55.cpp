#include <iostream>
#include <vector>
using namespace std;

/*
g++ 55.cpp -std=c++17 -o 55 && ./55
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx {0};
        int range {0};
        int size = nums.size();
        bool can_reach {true};

        while (idx < size && range < size) {

            if (nums.at(idx) == 0 && (range == nums.at(idx) + idx) && (idx != size - 1)) {
                can_reach = false;
                break;
            }

            range = range > (nums.at(idx) + idx)? range : nums.at(idx) + idx;

            if (range >= size - 1) {
                can_reach = true;
                break;
            }
            
            idx += 1;
        }

        return can_reach;
    }
};

int main() {

    Solution sol;

    // test case 01
    vector<int> nums {2,3,1,1,4};
    // ans: true
    cout << boolalpha << sol.canJump(nums) << endl;

    // test case 02
    nums = {3,2,1,0,4};
    // ans: false
    cout << sol.canJump(nums) << endl;

    return 0;
}