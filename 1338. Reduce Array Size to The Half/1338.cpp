#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
g++ 1338.cpp -std=c++17 -o 1338 && ./1338
*/

auto comp = [](int &a, int &b) {
    return a < b;
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int,int> umap;
        for (auto const &num: arr) {
            umap[num] += 1;
        }
        priority_queue<int, vector<int>, decltype(comp)> max_heap(comp);

        for (auto const &key: umap) {
            max_heap.push(key.second);
        }

        int cur_size {0};
        int ans {0};
        while (cur_size < size/2) {
            cur_size += max_heap.top();
            max_heap.pop();
            ans += 1;
        }
        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> arr {3,3,3,3,5,5,5,2,2,7};
    // Output: 2
    cout << sol.minSetSize(arr) << endl;

    arr = {7,7,7,7,7,7};
    // Output: 1
    cout << sol.minSetSize(arr) << endl;

    return 0;
}