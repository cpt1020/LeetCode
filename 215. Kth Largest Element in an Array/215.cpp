#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
g++ 215.cpp -std=c++17 -o 215 && ./215
*/

auto comp = [](int &a, int &b) {
    return a < b;
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, decltype(comp)> max_heap(comp);
        for (auto &num : nums) {
            max_heap.push(num);
        }

        for (int i {0}; i < k - 1; ++i) {
            max_heap.pop();
        }

        return max_heap.top();
    }
};

int main() {

    Solution sol;

    vector<int> nums {3,2,1,5,6,4};
    int k {2};
    // Output: 5
    cout << sol.findKthLargest(nums, k) << endl;

    nums = {3,2,3,1,2,4,5,5,6};
    k = 4;
    // Output: 4
    cout << sol.findKthLargest(nums, k) << endl;

    return 0;
}