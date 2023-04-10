#include <vector>
#include <iostream>
using namespace std;

/*
g++ 695.cpp -std=c++17 -o 695 && ./695
*/

class Solution {
private:

    void dfs(vector<vector<int>>& grid, int i, int j, int& area, const int& row, const int& col) {
        grid.at(i).at(j) = 2;
        area += 1;

        if (i+1 < row && grid.at(i+1).at(j) == 1) {
            dfs(grid, i+1, j, area, row, col);
        }
        if (i-1 >= 0 && grid.at(i-1).at(j) == 1) {
            dfs(grid, i-1, j, area, row, col);
        }
        if (j+1 < col && grid.at(i).at(j+1) == 1) {
            dfs(grid, i, j+1, area, row, col);
        }
        if (j-1 >= 0 && grid.at(i).at(j-1) == 1) {
            dfs(grid, i, j-1, area, row, col);
        }
    }

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea {0};
        int row = grid.size();
        int col = grid.at(0).size();

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    int area {0};
                    dfs(grid, i, j, area, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main() {

    Solution sol;

    // case 1 (ans: 6)
    vector<vector<int>> grid {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << sol.maxAreaOfIsland(grid) << endl;

    // case 2 (ans: 0)
    grid = {{0,0,0,0,0,0,0,0}};
    cout << sol.maxAreaOfIsland(grid) << endl;

    return 0;
}