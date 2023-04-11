#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        vector<int> prefixSum (arr.size() + 1);
        for (int i {0}; i <= arr.size(); ++i) {
            if (i == 0) {
                prefixSum.at(0) = 0;
            }
            else {
                prefixSum.at(i) = arr.at(i-1) + prefixSum.at(i-1);
            }
        }

        int ans {0};
        int size {1};

        while (size <= prefixSum.size()) {
            for (int i {size}; i < prefixSum.size(); ++i) {
                ans += (prefixSum.at(i) - prefixSum.at(i-size));
            }
            size += 2;
        }
        return ans;
    }
};

int main() {

    Solution sol;

    // case 1
    vector<int> arr {1,4,2,5,3};
    cout << sol.sumOddLengthSubarrays(arr) << endl;

    // case 2
    arr = {1,2};
    cout << sol.sumOddLengthSubarrays(arr) << endl;

    // case 3
    arr = {10,11,12};
    cout << sol.sumOddLengthSubarrays(arr) << endl;

    return 0;
}