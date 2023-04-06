#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& grid, size_t& row, size_t& col, int i, int j) {
        if (i >= row || j >= col || i < 0 || j < 0) {
            return false;
        }
        if (grid.at(i).at(j) == 1) {
            return true;
        } 

        grid.at(i).at(j) = 1;

        bool down {dfs(grid, row, col, i + 1, j)};
        bool up {dfs(grid, row, col, i - 1, j)};
        bool right {dfs(grid, row, col, i, j + 1)};
        bool left {dfs(grid, row, col, i, j - 1)};

        return down && up && right && left;
    }

    int closedIsland(vector<vector<int>>& grid) {
        size_t row {grid.size()};
        size_t col {grid.at(0).size()};
        int ans {0};

        for (int i {0}; i < row; i++) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 0) {
                    if (dfs(grid, row, col, i, j) == true) {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid {
        {1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}
    };
    cout << sol.closedIsland(grid) << endl;

    return 0;
}