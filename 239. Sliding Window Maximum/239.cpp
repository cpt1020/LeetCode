#include <iostream>
#include <queue>
#include <unordered_map>
#include "../utils.h"
using namespace std;

/*
g++ 239.cpp ../utils.cpp -std=c++17 -o 239 && ./239
*/

auto comp1 = [](int &a, int &b) {
    return a < b;
};

auto comp2 = [](pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
};

class Solution {
public:

    vector<int> maxSlidingWindow_v2(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp2)> max_heap(comp2);

        for (int i {0}; i < k; ++i) {
            max_heap.push({nums.at(i), i});
        }
        ans.push_back(max_heap.top().first);

        for (int i {k}; i < nums.size(); ++i) {
            max_heap.push({nums.at(i), i});
            while (max_heap.top().second < (i - k + 1)) {
                max_heap.pop();
            }
            ans.push_back(max_heap.top().first);
        }
        return ans;

    }

    vector<int> maxSlidingWindow_v1(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m; // 紀錄每個數字出現過的次數
        priority_queue<int, vector<int>, decltype(comp1)> max_heap(comp1); // 記錄目前的排行

        for (int i {0}; i < k; ++i) {
            m[nums.at(i)] += 1;
            if (m[nums.at(i)] == 1) {
                // 只允許第一次出現的數字才放到max_heap裡面
                max_heap.push(nums.at(i));
            }
        }
        ans.push_back(max_heap.top());

        for (int i {k}; i < nums.size(); ++i) {
            --m[nums.at(i - k)];
            // 將nums.at(i-k)的數字的出現次數減1

            if (++m[nums.at(i)] == 1) {
                // nums.at(i)出現的次數 + 1
                // 若 + 1後，他的次數是1
                // 也就是這個數字是第一次出現，那我才把他push到max_heap
                max_heap.push(nums.at(i));
            }
            
            // 若目前的最大值，他的出現次數是0
            // 代表他並沒有出現在目前的這個window
            // 所以要把他pop出去
            while (m[max_heap.top()] == 0) {
                max_heap.pop();
            }

            ans.push_back(max_heap.top());
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k {3};
    // Output: [3,3,5,5,6,7]
    printVector<int>(sol.maxSlidingWindow_v1(nums, k));
    printVector<int>(sol.maxSlidingWindow_v2(nums, k));

    nums = {9,10,9,-7,-4,-8,2,-6};
    k = 5;
    // Output: [10,10,9,2]
    printVector<int>(sol.maxSlidingWindow_v1(nums, k));
    printVector<int>(sol.maxSlidingWindow_v2(nums, k));

    return 0;
}