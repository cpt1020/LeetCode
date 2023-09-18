#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "../utils.h"
using namespace std;

/*
g++ 1337.cpp ../utils.cpp -std=c++17 -o 1337 && ./1337
*/

auto comp = [](pair<int,int> &p1, pair<int,int> &p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    else {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> min_heap(comp);
        // pair.first: the number of soldiers
        // pair.second: the row index

        for (int i {0}; i < mat.size(); ++i) {
            int soldier_num {0};
            for (int j {0}; j < mat.at(0).size(); ++j) {
                if (mat.at(i).at(j) == 1) {
                    soldier_num += 1;
                }
            }
            min_heap.push({soldier_num, i});
        }
        
        vector<int> ans;
        for (int i {0}; i < k; ++i) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> mat {{1,1,0,0,0},
                            {1,1,1,1,0},
                            {1,0,0,0,0},
                            {1,1,0,0,0},
                            {1,1,1,1,1}};
    int k {3};
    // Output: [2,0,3]
    printVector<int>(sol.kWeakestRows(mat, k));

    mat = {{1,0,0,0},
           {1,1,1,1},
           {1,0,0,0},
           {1,0,0,0}};
    k = 2;
    // Output: [0,2]
    printVector<int>(sol.kWeakestRows(mat, k));

    return 0;
}