#include <utility>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
g++ 463.cpp -std=c++17 -o 463 && ./463
*/

class Solution {
public:

    void bfs(vector<vector<int>>& grid, int i, int j, const int& row, const int& col, int& perimeter) {
        queue<pair<int, int>> q;
        q.push({i, j});

        while (q.empty() != true) {
            int r {q.front().first};
            int c {q.front().second};
            grid.at(r).at(c) = 2;
            q.pop();

            if (r + 1 < row && grid.at(r+1).at(c) == 1) {
                grid.at(r+1).at(c) = 2;
                q.push({r+1, c});
            }
            else if (r + 1 < row && grid.at(r+1).at(c) == 0) {
                perimeter += 1;
            }
            if (r - 1 >= 0 && grid.at(r-1).at(c) == 1) {
                grid.at(r-1).at(c) = 2;
                q.push({r-1, c});
            }
            else if (r - 1 >= 0 && grid.at(r-1).at(c) == 0) {
                perimeter += 1;
            }
            if (c + 1 < col && grid.at(r).at(c + 1) == 1) {
                grid.at(r).at(c+1) = 2;
                q.push({r, c + 1});
            }
            else if (c + 1 < col && grid.at(r).at(c + 1) == 0) {
                perimeter += 1;
            }
            if (c - 1 >= 0 && grid.at(r).at(c - 1) == 1) {
                grid.at(r).at(c-1) = 2;
                q.push({r, c - 1});
            }
            else if (c - 1 >= 0 && grid.at(r).at(c - 1) == 0) {
                perimeter += 1;
            }

            if (r + 1 == row) perimeter += 1;
            if (r - 1 < 0) perimeter += 1;
            if (c + 1 == col) perimeter += 1;
            if (c - 1 < 0) perimeter += 1;
        }
    }

    void dfs(vector<vector<int>>& grid, int i, int j, const int& row, const int& col, int& perimeter) {
        grid.at(i).at(j) = 2;
        if (i + 1 == row) perimeter += 1;
        if (i - 1 < 0) perimeter += 1;
        if (j + 1 == col) perimeter += 1;
        if (j - 1 < 0) perimeter += 1;

        if (i + 1 < row && grid.at(i+1).at(j) == 1) {
            grid.at(i+1).at(j) = 2;
            dfs(grid, i+1, j, row, col, perimeter);
        }
        else if (i + 1 < row && grid.at(i+1).at(j) == 0) {
            perimeter += 1;
        }

        if (i - 1 >= 0 && grid.at(i-1).at(j) == 1) {
            grid.at(i-1).at(j) = 2;
            dfs(grid, i-1, j, row, col, perimeter);
        }
        else if (i - 1 >= 0 && grid.at(i-1).at(j) == 0) {
            perimeter += 1;
        }

        if (j + 1 < col && grid.at(i).at(j+1) == 1) {
            grid.at(i).at(j+1) = 2;
            dfs(grid, i, j+1, row, col, perimeter);
        }
        else if (j + 1 < col && grid.at(i).at(j+1) == 0) {
            perimeter += 1;
        }

        if (j - 1 >= 0 && grid.at(i).at(j-1) == 1) {
            grid.at(i).at(j-1) = 2;
            dfs(grid, i, j-1, row, col, perimeter);
        }
        else if (j - 1 >= 0 && grid.at(i).at(j-1) == 0) {
            perimeter += 1;
        }

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        size_t row {grid.size()};
        size_t col {grid.at(0).size()};
        int perimeter {0};
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    // bfs(grid, i, j, row, col, perimeter);
                    dfs(grid, i, j, row, col, perimeter);
                    break;
                }
            }
        }
        return perimeter;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> grid {
        {1,1},{1,1}
    };
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}