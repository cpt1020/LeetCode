#include <vector>
#include <iostream>
// #include <queue>
// #include <utility>
using namespace std;

/*
g++ 1905.cpp -std=c++17 -o 1905 && ./1905
*/

class Solution {
private:

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, const int& row, const int& col) {
        grid1.at(i).at(j) = 2;
        grid2.at(i).at(j) = 2;

        bool down {true}, up {true}, right {true}, left {true};

        if (i+1 < row && grid2.at(i+1).at(j) == 1) {
            if (grid1.at(i+1).at(j) != 1) {
                down = false;
            }
            else {
                down = dfs(grid1, grid2, i+1, j, row, col);
            }
        }
        if (i-1 >= 0 && grid2.at(i-1).at(j) == 1) {
            if (grid1.at(i-1).at(j) != 1) {
                up = false;
            }
            else {
                up = dfs(grid1, grid2, i-1, j, row, col);
            }
        }
        if (j+1 < col && grid2.at(i).at(j+1) == 1) {
            if (grid1.at(i).at(j+1) != 1) {
                right = false;
            }
            else {
                right = dfs(grid1, grid2, i, j+1, row, col);
            }
        }
        if (j-1>= 0 && grid2.at(i).at(j-1) == 1) {
            if (grid1.at(i).at(j-1) != 1) {
                left = false;
            }
            else {
                left = dfs(grid1, grid2, i, j-1, row, col);
            }
        }
        return (down && up && left && right);
    }

public:

    int countSubIslands_DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid1.size();
        int col = grid1.at(0).size();
        int ans {0};

        for (int i {0}; i < row; i++) {
            for (int j {0}; j < col; ++j) {
                if (grid1.at(i).at(j) == 1 && grid2.at(i).at(j) == 1) {
                    if (dfs(grid1, grid2, i, j, row, col) == true) {
                        ans += 1;
                    }
                }
            }
        }

        return ans;
    }

};

int main() {

    Solution sol;

    vector<vector<int>> grid1 {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    cout << sol.countSubIslands_DFS(grid1, grid2) << endl;

    grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
    cout << sol.countSubIslands_DFS(grid1, grid2) << endl;

    return 0;
}