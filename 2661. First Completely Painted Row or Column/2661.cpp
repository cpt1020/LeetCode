#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
g++ 2661.cpp -std=c++17 -o 2661 && ./2661
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.at(0).size();
        
        unordered_map<int, pair<int,int>> umap;
        for (int i {0}; i < m; ++i) {
            for (int j {0}; j < n; ++j) {
                umap[mat.at(i).at(j)] = {i,j};
            }
        }
        
        vector<int> row (m, 0);
        vector<int> col (n, 0);

        for (int i {0}; i < arr.size(); ++i) {
            row.at(umap[arr.at(i)].first) += 1;
            col.at(umap[arr.at(i)].second) += 1;

            if (row.at(umap[arr.at(i)].first) == n) {
                return i;
            }
            if (col.at(umap[arr.at(i)].second) == m) {
                return i;
            }
        }

        return 0;
    }
};

int main() {

    Solution sol;

    vector<int> arr {1,3,4,2};
    vector<vector<int>> mat {{1,4},{2,3}};
    // Output: 2
    cout << sol.firstCompleteIndex(arr, mat) << endl;

    arr = {2,8,7,4,1,3,5,6,9};
    mat = {{3,2,5},{1,4,6},{8,7,9}};
    // Output: 3
    cout << sol.firstCompleteIndex(arr, mat) << endl;

    return 0;
}