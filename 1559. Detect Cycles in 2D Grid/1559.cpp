#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

/*
g++ 1559.cpp -std=c++17 -o 1559 && ./1559
*/

class Solution {
private:
    void dfs(vector<vector<char>>& grid, const int& row, const int& col, vector<vector<bool>>& visit, bool& ans, int i, int j, const char& val, int previ, int prevj) {
        visit.at(i).at(j) = true;
        
        if (i + 1 < row && i+1 != previ && grid.at(i+1).at(j) == val && visit.at(i+1).at(j) == true) {
            ans = true;
            return;
        }
        if (i - 1 >= 0 && i-1 != previ && grid.at(i-1).at(j) == val && visit.at(i-1).at(j) == true) {
            ans = true;
            return;
        }
        if (j + 1 < col && j+1 != prevj && grid.at(i).at(j+1) == val && visit.at(i).at(j+1) == true) {
            ans = true;
            return;
        }
        if (j - 1 >= 0 && j-1 != prevj && grid.at(i).at(j-1) == val && visit.at(i).at(j-1) == true) {
            ans = true;
            return;
        }

        if (i + 1 < row && grid.at(i+1).at(j) == val && visit.at(i+1).at(j) == false) {
            dfs(grid, row, col, visit, ans, i+1, j, val, i, j);
        }
        if (i - 1 >= 0 && grid.at(i-1).at(j) == val && visit.at(i-1).at(j) == false) {
            dfs(grid, row, col, visit, ans, i-1, j, val, i, j);
        }
        if (j + 1 < col && grid.at(i).at(j+1) == val && visit.at(i).at(j+1) == false) {
            dfs(grid, row, col, visit, ans, i, j+1, val, i, j);
        }
        if (j - 1 >= 0 && grid.at(i).at(j-1) == val && visit.at(i).at(j-1) == false) {
            dfs(grid, row, col, visit, ans, i, j-1, val, i, j);
        }
    }
public:
    bool containsCycle_dfs(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid.at(0).size();
        vector<vector<bool>> visit (row, vector<bool>(col, 0));
        bool ans {false};

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (visit.at(i).at(j) == false) {
                    dfs(grid, row, col, visit, ans, i, j, grid.at(i).at(j), -1, -1);

                    if (ans == true) {
                        return ans;
                    }
                }
            }
        }

        return ans;
    }

    bool containsCycle_bfs(vector<vector<char>>& grid) {
        // The basic idea is that if there is a cell that can be reached via more than one direction in BFS search,
        // then there is a loop
        
        int row = grid.size();
        int col = grid.at(0).size();
        vector<vector<bool>> visit (row, vector<bool>(col, 0));
        queue<pair<int, int>> q;

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (visit.at(i).at(j) == false) {
                    q.push({i, j});
                    visit.at(i).at(j) = true;
                    const char val {grid.at(i).at(j)};

                    while (q.empty() != true) {
                        map<pair<int,int>, int> mp;
                        int s = q.size();
                        for (int i {0}; i < s; ++i) {
                            if (mp[q.front()] == 1) {
                                return true;
                            }
                            else {
                                mp[q.front()] += 1;
                            }

                            int r {q.front().first};
                            int c {q.front().second};
                            visit.at(r).at(c) = true;
                            q.pop();

                            if (r+1 < row && grid.at(r+1).at(c) == val && visit.at(r+1).at(c) == false) {
                                q.push({r+1, c});
                            }
                            if (r-1 >= 0 && grid.at(r-1).at(c) == val && visit.at(r-1).at(c) == false) {
                                q.push({r-1, c});
                            }
                            if (c+1 < col && grid.at(r).at(c+1) == val && visit.at(r).at(c+1) == false) {
                                q.push({r, c+1});
                            }
                            if (c-1 >= 0 && grid.at(r).at(c-1) == val && visit.at(r).at(c-1) == false) {
                                q.push({r, c-1});
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};

int main() {

    Solution sol;

    vector<vector<char>> grid {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    // Output: true
    cout << boolalpha << sol.containsCycle_dfs(grid) << endl;
    cout << boolalpha << sol.containsCycle_bfs(grid) << endl;

    grid = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    // Output: true
    cout << boolalpha << sol.containsCycle_dfs(grid) << endl;
    cout << boolalpha << sol.containsCycle_bfs(grid) << endl;

    grid = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    // Output: false
    cout << boolalpha << sol.containsCycle_dfs(grid) << endl;
    cout << boolalpha << sol.containsCycle_bfs(grid) << endl;

    grid = {{'b','a','c'},{'c','a','c'},{'d','d','c'},{'b','c','c'}};
    // Output: false
    cout << boolalpha << sol.containsCycle_dfs(grid) << endl;
    cout << boolalpha << sol.containsCycle_bfs(grid) << endl;

    return 0;
}