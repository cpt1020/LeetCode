#include <vector>
#include <iostream>
using namespace std;

/*
g++ 200.cpp -std=c++17 -o 200 && ./200
*/

class Solution {
private:

    void dfs(vector<vector<char>>& grid, const int& row, const int& col, int i, int j) {
        grid.at(i).at(j) = '2';

        if (i+1 < row && grid.at(i+1).at(j) == '1') {
            dfs(grid, row, col, i+1, j);
        }
        if (i-1 >= 0 && grid.at(i-1).at(j) == '1') {
            dfs(grid, row, col, i-1, j);
        }
        if (j+1 < col && grid.at(i).at(j+1) == '1') {
            dfs(grid, row, col, i, j+1);
        }
        if (j-1 >= 0 && grid.at(i).at(j-1) == '1') {
            dfs(grid, row, col, i, j-1);
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {
        int res {0};
        int row = grid.size();
        int col = grid.at(0).size();

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == '1') {
                    dfs(grid, row, col, i, j);
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main(){

    Solution sol;

    // case 1
    vector<vector<char>> grid {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    // ans: 1
    cout << sol.numIslands(grid) << endl;

    // case 2
    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    // ans: 3
    cout << sol.numIslands(grid) << endl;

    return 0;
}