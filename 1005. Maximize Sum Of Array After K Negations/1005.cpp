#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
g++ 1005.cpp -std=c++17 -o 1005 && ./1005
*/

auto comp = [](int &a, int &b) {
    return a > b;
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, decltype(comp)> min_heap(comp);
        for (auto &num: nums) {
            min_heap.push(num);
        }

        for (int i {0}; i < k; ++i) {
            int min_num {min_heap.top()};
            min_heap.pop();
            min_heap.push(min_num * -1);
        }

        int sum {0};
        while (min_heap.empty() != true) {
            sum += min_heap.top();
            min_heap.pop();
        }

        return sum;
    }
};

int main() {

    Solution sol;

    vector<int> nums {4,2,3};
    int k {1};
    // Output: 5
    cout << sol.largestSumAfterKNegations(nums, k) << endl;

    nums = {2,-3,-1,5,-4};
    k = 2;
    // Output: 13
    cout << sol.largestSumAfterKNegations(nums, k) << endl;

    return 0;
}