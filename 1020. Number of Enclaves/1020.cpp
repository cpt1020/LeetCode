#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// g++ 1020.cpp -std=c++17 -o 1020 && ./1020

class Solution {
public:

    void dfs(vector<vector<int>>& grid, const size_t& row, const size_t& col, int i, int j) {
        grid.at(i).at(j) = 2;

        if (i + 1 < row && grid.at(i + 1).at(j) == 1) {
            grid.at(i+1).at(j) = 2;
            dfs(grid, row, col, i+1, j);
        }
        if (i - 1 >= 0 && grid.at(i-1).at(j) == 1) {
            grid.at(i-1).at(j) = 2;
            dfs(grid, row, col, i-1, j);
        }
        if (j + 1 < col && grid.at(i).at(j + 1) == 1) {
            grid.at(i).at(j+1) = 2;
            dfs(grid, row, col, i, j + 1);
        }
        if (j - 1 >= 0 && grid.at(i).at(j - 1) == 1) {
            grid.at(i).at(j-1) = 2;
            dfs(grid, row, col, i, j - 1);
        }
    }

    void bfs(vector<vector<int>>& grid, int& ans, const size_t& row, const size_t& col, int i, int j) {
        grid.at(i).at(j) = 2;
        ans += 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (q.empty() != true) {
            int r {q.front().first};
            int c {q.front().second};
            q.pop();

            if (r + 1 < row && grid.at(r+1).at(c) == 1) {
                grid.at(r+1).at(c) = 2;
                ans += 1;
                q.push({r+1, c});
            }
            if (r - 1 >= 0 && grid.at(r-1).at(c) == 1) {
                grid.at(r-1).at(c) = 2;
                ans += 1;
                q.push({r-1, c});
            }
            if (c + 1 < col && grid.at(r).at(c+1) == 1) {
                grid.at(r).at(c+1) = 2;
                ans += 1;
                q.push({r, c + 1});
            }
            if (c - 1 >= 0 && grid.at(r).at(c-1) == 1) {
                grid.at(r).at(c-1) = 2;
                ans += 1;
                q.push({r, c - 1});
            }
        }

        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        size_t row {grid.size()};
        size_t col {grid.at(0).size()};
        int ans {0};

        for (int i {0}; i < col; ++i) {
            if (grid.at(0).at(i) == 1) {
                dfs(grid, row, col, 0, i);
            }
            if (grid.at(row-1).at(i) == 1) {
                dfs(grid, row, col, row-1, i);
            }
        }

        for (int i {0}; i < row; ++i) {
            if (grid.at(i).at(0) == 1) {
                dfs(grid, row, col, i, 0);
            }
            if (grid.at(i).at(col-1) == 1) {
                dfs(grid, row, col, i, col-1);
            }
        }

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    bfs(grid, ans, row, col, i, j);
                }
            }
        }

        return ans;
    }
};


int main() {

    Solution sol;

    vector<vector<int>> grid {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << sol.numEnclaves(grid) << endl;

    return 0;
}