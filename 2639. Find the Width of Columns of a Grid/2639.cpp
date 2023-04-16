#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 2639.cpp ../utils.cpp -std=c++17 -o 2639 && ./2639
*/

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int col = grid.at(0).size();
        int row = grid.size();
        vector<int> ans (col);
        
        for (int i {0}; i < col; ++i) {
            int maxLen {INT_MIN};
            for (int j {0}; j < row; ++j) {
                string s {to_string(grid.at(j).at(i))};
                int size = s.size();
                maxLen = max(maxLen, size);
            }
            ans.at(i) = maxLen;
            
        }
        
        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid {{1},{22},{333}};
    printVector(sol.findColumnWidth(grid));

    grid = {{-15,1,3}, {15,7,12}, {5,6,-2}};
    printVector(sol.findColumnWidth(grid));

    return 0;
}