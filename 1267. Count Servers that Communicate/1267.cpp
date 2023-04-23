#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
g++ 1267.cpp -std=c++17 -o 1267 && ./1267
*/

class Solution {
private:

    void dfs(vector<vector<int>>& grid, const int& row, const int& col, int i, int j, int& server) {
        grid.at(i).at(j) = 2;
        server += 1;

        for (int c {0}; c < col; ++c) {
            if (grid.at(i).at(c) == 1) {
                dfs(grid, row, col, i, c, server);
            }
        }

        for (int r {0}; r < row; ++r) {
            if (grid.at(r).at(j) == 1) {
                dfs(grid, row, col, r, j, server);
            }
        }
    }

    void dfs_optimized(vector<vector<int>>& grid, const int& row, const int& col, int i, int j, int& server, vector<vector<int>>& rowGra, vector<vector<int>>& colGra) {
        grid.at(i).at(j) = 2;
        server += 1;

        for (auto c: rowGra.at(i)) {
            if (grid.at(i).at(c) == 1) {
                dfs_optimized(grid, row, col, i, c, server, rowGra, colGra);
            }
        }

        for (auto r: colGra.at(j)) {
            if (grid.at(r).at(j) == 1) {
                dfs_optimized(grid, row, col, r, j, server, rowGra, colGra);
            }
        }
    }

public:

    int countServers_DFS(vector<vector<int>> grid) {
        int row = grid.size();
        int col = grid.at(0).size();
        
        int res {0};
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    int server {0};
                    dfs(grid, row, col, i, j, server);
                    if (server != 1) {
                        res += server;
                    }
                }
            }
        }
        return res;
    }

    int countServers_BFS(vector<vector<int>> grid) {
        int row = grid.size();
        int col = grid.at(0).size();
        
        int res {0};
        queue<pair<int, int>> q;
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    int server {0};
                    q.push({i,j});
                    grid.at(i).at(j) = 2;

                    while (q.empty() != true) {
                        int r {q.front().first};
                        int c {q.front().second};
                        server += 1;
                        q.pop();

                        for (int m {0}; m < row; ++m) {
                            if (grid.at(m).at(c) == 1) {
                                q.push({m, c});
                                grid.at(m).at(c) = 2;
                            }
                        }

                        for (int n {0}; n < col; ++n) {
                            if (grid.at(r).at(n) == 1) {
                                q.push({r, n});
                                grid.at(r).at(n) = 2;
                            }
                        }
                    }

                    if (server != 1) {
                        res += server;
                    }
                }
            }
        }
        return res;
    }

    int countServers_BFS_optimized(vector<vector<int>> grid) {
        int row = grid.size();
        int col = grid.at(0).size();

        vector<vector<int>> rowGra (row);
        vector<vector<int>> colGra (col);
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    rowGra.at(i).push_back(j);
                    colGra.at(j).push_back(i);
                }
            }
        }
        
        int res {0};
        queue<pair<int, int>> q;

        for (int i {0}; i < row; ++i) {
            for (auto j: rowGra.at(i)) {
                if (grid.at(i).at(j) == 1) {
                    int server {0};
                    q.push({i,j});
                    grid.at(i).at(j) = 2;

                    while (q.empty() != true) {
                        int r {q.front().first};
                        int c {q.front().second};
                        server += 1;
                        q.pop();

                        for (auto n: rowGra.at(r)) {
                            if (grid.at(r).at(n) == 1) {
                                grid.at(r).at(n) = 2;
                                q.push({r, n});
                            }
                        }

                        for (auto n: colGra.at(c)) {
                            if (grid.at(n).at(c) == 1) {
                                grid.at(n).at(c) = 2;
                                q.push({n, c});
                            }
                        }
                    }

                    if (server != 1) {
                        res += server;
                    }
                }
            }
        }
        return res;
    }

    int countServers_DFS_optimized(vector<vector<int>> grid) {
        int row = grid.size();
        int col = grid.at(0).size();
        
        vector<vector<int>> rowGra (row);
        vector<vector<int>> colGra (col);
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    rowGra.at(i).push_back(j);
                    colGra.at(j).push_back(i);
                }
            }
        }

        int res {0};

        for (int i {0}; i < row; ++i) {
            for (auto j: rowGra.at(i)) {
                if (grid.at(i).at(j) == 1) {
                    int server {0};
                    dfs_optimized(grid, row, col, i, j, server, rowGra, colGra);
                    if (server != 1) {
                        res += server;
                    }
                }
            }
        }

        return res;
    }

    int countServers_optimized(vector<vector<int>> grid) {
        int row = grid.size();
        int col = grid.at(0).size();

        vector<int> rowCount (row, 0);
        vector<int> colCount (col, 0);

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1) {
                    rowCount.at(i) += 1;
                    colCount.at(j) += 1;
                }
            }
        }

        int res {0};

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (grid.at(i).at(j) == 1 && (rowCount.at(i) > 1 || colCount.at(j) > 1)) {
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid {{1,0},{0,1}};
    // ans: 0
    cout << sol.countServers_DFS(grid) << endl;
    cout << sol.countServers_DFS_optimized(grid) << endl;
    cout << sol.countServers_BFS(grid) << endl;
    cout << sol.countServers_BFS_optimized(grid) << endl;
    cout << sol.countServers_optimized(grid) << endl;

    grid = {{1,0},{1,1}};
    // ans: 3
    cout << sol.countServers_DFS(grid) << endl;
    cout << sol.countServers_DFS_optimized(grid) << endl;
    cout << sol.countServers_BFS(grid) << endl;
    cout << sol.countServers_BFS_optimized(grid) << endl;
    cout << sol.countServers_optimized(grid) << endl;

    grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    // ans: 4
    cout << sol.countServers_DFS(grid) << endl;
    cout << sol.countServers_DFS_optimized(grid) << endl;
    cout << sol.countServers_BFS(grid) << endl;
    cout << sol.countServers_BFS_optimized(grid) << endl;
    cout << sol.countServers_optimized(grid) << endl;

    grid = {{1,0,0,1,0},{0,0,0,0,0},{0,0,0,1,0}};
    // ans: 3
    cout << sol.countServers_DFS(grid) << endl;
    cout << sol.countServers_DFS_optimized(grid) << endl;
    cout << sol.countServers_BFS(grid) << endl;
    cout << sol.countServers_BFS_optimized(grid) << endl;
    cout << sol.countServers_optimized(grid) << endl;

    return 0;
}