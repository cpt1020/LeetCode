#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 347.cpp ../utils.cpp -std=c++17 -o 347 && ./347
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (auto& num: nums) {
            umap[num] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        // pair.first is freq
        // pair.second is num
        
        for (auto& key: umap) {
            pq.push({key.second, key.first});
        }

        vector<int> ans;
        for (int i {0}; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums {1,1,1,2,2,3};
    int k {2};
    // Output: [1,2]
    printVector<int>(sol.topKFrequent(nums, k));

    nums = {1};
    k = 1;
    // Output: [1]
    printVector<int>(sol.topKFrequent(nums, k));

    return 0;
}