#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1343.cpp -std=c++17 -o 1343 && ./1343
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans {0};
        int sum {0};
        for (int i {0}; i < k; ++i) {
            sum += arr.at(i);
        }
        if (sum/k >= threshold) {
            ans += 1;
        }

        for (int i {k}; i < arr.size(); ++i) {
            sum += arr.at(i);
            sum -= arr.at(i-k);

            if (sum/k >= threshold) {
                ans += 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> arr {2,2,2,2,5,5,5,8};
    int k {3};
    int threshold {4};
    // Output: 3
    cout << sol.numOfSubarrays(arr, k, threshold) << endl;

    arr = {11,13,17,23,29,31,7,5,2,3};
    threshold = 5;
    // Output: 6
    cout << sol.numOfSubarrays(arr, k, threshold) << endl;

    return 0;
}