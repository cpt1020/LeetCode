#include <vector>
#include <iostream>
using namespace std;

/*
g++ 2658.cpp -std=c++17 -o 2658 && ./2658
*/

class Solution {
private:
    void dfs(vector<vector<int>>& grid, const int& row, const int& col, int i, int j, int& fish) {
        fish += grid.at(i).at(j);
        grid.at(i).at(j) = 0;
        
        if (i + 1 < row && grid.at(i+1).at(j) != 0) {
            dfs(grid, row, col, i+1, j, fish);
        }
        if (i - 1 >= 0 && grid.at(i-1).at(j) != 0) {
            dfs(grid, row, col, i-1, j, fish);
        }
        if (j + 1 < col && grid.at(i).at(j+1) != 0) {
            dfs(grid, row, col, i, j+1, fish);
        }
        if (j -1 >= 0 && grid.at(i).at(j-1) != 0) {
            dfs(grid, row, col, i, j-1, fish);
        }   
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res {0};
        int row = grid.size();
        int col = grid.at(0).size();

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) != 0) {
                    int fish {0};
                    dfs(grid, row, col, i, j, fish);
                    res = max(res, fish);
                }
            }
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    // Output: 7
    cout << sol.findMaxFish(grid) << endl;

    grid = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}};
    // Output: 1
    cout << sol.findMaxFish(grid) << endl;

    return 0;
}