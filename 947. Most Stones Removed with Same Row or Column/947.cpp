#include <vector>
#include <iostream>
#include <set>
using namespace std;

/*
g++ 947.cpp -std=c++17 -o 947 && ./947
*/

class Solution {
private:

    void dfs(const vector<vector<int>>& rowGraph, const vector<vector<int>>& colGraph, set<vector<int>>& visit, int& i, int& j, int& stone) {
        visit.insert({i, j});
        stone += 1;

        for (auto c: rowGraph.at(i)) {
            if (visit.find({i,c}) == visit.end()) {
                dfs(rowGraph, colGraph, visit, i, c, stone);
            }
        }

        for (auto r: colGraph.at(j)) {
            if (visit.find({r,j}) == visit.end()) {
                dfs(rowGraph, colGraph, visit, r, j, stone);
            }
        }
    }

    void dfs_optimized(vector<vector<int>>& stones, const int& n,vector<bool>& visit, int& i, int& stone) {
        visit.at(i) = true;
        stone += 1;

        for (int j {0}; j < n; ++j) {
            if (visit.at(j) == false && (stones.at(i).at(0) == stones.at(j).at(0) || stones.at(i).at(1) == stones.at(j).at(1))) {
                dfs_optimized(stones, n, visit, j, stone);
            } 
        }
    }

    int findSet(vector<int>& parent, int& i) {
        if (parent.at(i) != i) {
            parent.at(i) = findSet(parent, parent.at(i));
        }
        return parent.at(i);
    }

    void unionSet(vector<int>& parent, int& i, int& j) {
        int parent1 {findSet(parent, i)};
        int parent2 {findSet(parent, j)};

        if (parent1 != parent2) {
            parent[max(parent1, parent2)] = min(parent1, parent2);
        }
    }

public:

    int removeStones_DFS(vector<vector<int>>& stones) {
        if (stones.size() == 1) {
            return 0;
        }

        int row {INT_MIN};
        int col {INT_MIN};
        for (auto vec: stones) {
            row = max(row, vec.at(0));
            col = max(col, vec.at(1));
        }

        row++;
        col++;

        vector<vector<int>> rowGraph (row);
        vector<vector<int>> colGraph (col); 

        for (auto vec: stones) {
            rowGraph.at(vec.at(0)).push_back(vec.at(1));
            colGraph.at(vec.at(1)).push_back(vec.at(0));
        }

        int ans {0};
        set<vector<int>> visit;

        for (int i {0}; i < row; ++i) {
            if (rowGraph.at(i).empty() != true) {
                for (auto j: rowGraph.at(i)) {
                    if (visit.find({i,j}) == visit.end()) {
                        int stone {-1};
                        dfs(rowGraph, colGraph, visit, i, j, stone);
                        ans += stone;
                    }
                }
            }
        }

        return ans;
    }

    int removeStones_DFS_optimized(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visit (n, false);

        int res {0};
        for (int i {0}; i < n; ++i) {
            if (visit.at(i) == false) {
                int stone {-1};
                dfs_optimized(stones, n, visit, i, stone);
                res += stone;
            }
        }

        return res;
    }

    int removeStones_UnionFind(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> parent (n);
        for (int i {0}; i < n; ++i) {
            parent.at(i) = i;
        }

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < i; ++j) {
                if (stones.at(i).at(0) == stones.at(j).at(0) || stones.at(i).at(1) == stones.at(j).at(1)) {
                    unionSet(parent, i, j);
                }
            }
        }

        int stone {0};

        for (int i {0}; i < n; ++i) {
            if (parent.at(i) == i) {
                stone += 1;
            }
        }

        return n - stone;
    }

};

int main() {
    
    Solution sol;
    vector<vector<int>> stones {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    // ans: 5
    cout << sol.removeStones_DFS(stones) << endl;
    cout << sol.removeStones_DFS_optimized(stones) << endl;
    cout << sol.removeStones_UnionFind(stones) << endl;

    stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    // ans: 3
    cout << sol.removeStones_DFS(stones) << endl;
    cout << sol.removeStones_DFS_optimized(stones) << endl;
    cout << sol.removeStones_UnionFind(stones) << endl;

    stones = {{0,0}};
    // ans: 0
    cout << sol.removeStones_DFS(stones) << endl;
    cout << sol.removeStones_DFS_optimized(stones) << endl;
    cout << sol.removeStones_UnionFind(stones) << endl;

    stones = {{3,2},{0,0},{3,3},{2,1},{2,3},{2,2},{0,2}};
    // ans: 6
    cout << sol.removeStones_DFS(stones) << endl;
    cout << sol.removeStones_DFS_optimized(stones) << endl;
    cout << sol.removeStones_UnionFind(stones) << endl;

    stones = {{3,2},{3,1},{4,4},{1,1},{0,2},{4,0}};
    // ans: 4
    cout << sol.removeStones_DFS(stones) << endl;
    cout << sol.removeStones_DFS_optimized(stones) << endl;
    cout << sol.removeStones_UnionFind(stones) << endl;

    return 0;
}