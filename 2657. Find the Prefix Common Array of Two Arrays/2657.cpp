#include <vector>
#include <unordered_map>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 2657.cpp ../utils.cpp -std=c++17 -o 2657 && ./2657
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> umap;
        vector<int> res;

        for (int i {0}; i < A.size(); ++i) {
            umap[A.at(i)] += 1;
            umap[B.at(i)] += 1;
            int cnt {0};
            for (auto& key: umap) {
                if (key.second > 1) {
                    cnt += 1;
                }
            }
            res.push_back(cnt);
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<int> A {1,3,2,4};
    vector<int> B {3,1,2,4};
    // Output: [0,2,3,4]
    printVector<int>(sol.findThePrefixCommonArray(A, B));

    A = {2,3,1};
    B = {3,1,2};
    // Output: [0,1,3]
    printVector<int>(sol.findThePrefixCommonArray(A, B));

    return 0;
}