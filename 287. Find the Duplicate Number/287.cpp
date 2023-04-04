#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
g++ 287.cpp -std=c++17 -o 287 && ./287
*/

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int low {1};
        int high {static_cast<int>(nums.size()) - 1};

        while (low < high) {
            int mid {low + (high - low)/2};
            int count {0};
            for (auto num: nums) {
                if (num <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {

    Solution sol;

    vector<int> nums {1,3,4,2,2};
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}