#include <vector>
#include <util.h>
#include <queue>
#include <iostream>
using namespace std;

/*
g++ 994.cpp -std=c++17 -o 994 && ./994
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row {static_cast<int>(grid.size())};
        int col {static_cast<int>(grid.at(0).size())};

        queue<pair<int, int>> q;

        int fresh {0};
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 2) {
                    q.push({i, j});
                }
                else if (grid.at(i).at(j) == 1) {
                    fresh += 1;
                }
            }
        }

        int time {-1};
        while (q.empty() != true) {
            int q_size {static_cast<int>(q.size())};

            for (int i {0}; i < q_size; ++i) {
                int r {q.front().first};
                int c {q.front().second};
                q.pop();

                if (r + 1 < row && grid.at(r+1).at(c) == 1) {
                    q.push({r+1, c});
                    grid.at(r+1).at(c) = 2;
                    fresh -= 1;
                }
                if (r - 1 >= 0 && grid.at(r-1).at(c) == 1) {
                    q.push({r-1, c});
                    grid.at(r-1).at(c) = 2;
                    fresh -= 1;
                }
                if (c + 1 < col && grid.at(r).at(c + 1) == 1) {
                    q.push({r, c + 1});
                    grid.at(r).at(c + 1) = 2;
                    fresh -= 1;
                }
                if (c - 1 >= 0 && grid.at(r).at(c - 1) == 1) {
                    q.push({r, c - 1});
                    grid.at(r).at(c - 1) = 2;
                    fresh -= 1;
                }
            }
            time += 1;
        }

        if (fresh > 0) {
            return -1;
        }
        if (time == -1) {
            return 0;
        }
        return time;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(grid) << endl;

    return 0;
}