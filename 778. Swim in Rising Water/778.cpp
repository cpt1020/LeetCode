#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/*
g++ 778.cpp -std=c++17 -o 778 && ./778
*/

auto comp = [](const vector<int>& a, const vector<int>& b) {
    return a.at(0) > b.at(0);
};

class Solution {
private:

    void dfs(vector<vector<int>>& grid, vector<vector<bool>> visit, int& res, int i, int j, int currMax, const int& target) {
        visit.at(i).at(j) = true;

        if (grid.at(i).at(j) == target) {
            if (currMax < res) {
                res = currMax;
            }
            return;
        }

        if (i+1 < grid.size() && visit.at(i+1).at(j) == false) {
            int tmpMax = max(grid.at(i+1).at(j), currMax);
            dfs(grid, visit, res, i+1, j, tmpMax, target);
        }
        if (i-1 >= 0 && visit.at(i-1).at(j) == false) {
            int tmpMax = max(grid.at(i-1).at(j), currMax);
            dfs(grid, visit, res, i-1, j, tmpMax, target);
        }
        if (j+1 < grid.size() && visit.at(i).at(j+1) == false) {
            int tmpMax = max(grid.at(i).at(j+1), currMax);
            dfs(grid, visit, res, i, j+1, tmpMax, target);
        }
        if (j-1 >= 0 && visit.at(i).at(j-1) == false) {
            int tmpMax = max(grid.at(i).at(j-1), currMax);
            dfs(grid, visit, res, i, j-1, tmpMax, target);
        }
    }

public:

    // DFS version encounters TLE for 6*6 grid
    int swimInWater_DFS(vector<vector<int>>& grid) {
        int res {INT_MAX};
        vector<vector<bool>> visit (grid.size(), vector<bool> (grid.size(), false));
        dfs(grid, visit, res, 0, 0, grid.at(0).at(0), grid.at(grid.size()-1).at(grid.size()-1));
        return res;
    }

    int swimInWater_Dijkstra(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit (n, vector<bool> (n, false));
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
        minHeap.push({grid.at(0).at(0), 0, 0});
        visit.at(0).at(0) = true;

        int destination {grid.at(n-1).at(n-1)};
        int res {0};

        while (minHeap.empty() != true) {
            auto cur {minHeap.top()};
            minHeap.pop();
            
            if (cur.at(0) > res) {
                res = cur.at(0);
            }

            if (cur.at(0) == destination) {
                break;
            }

            int i {cur.at(1)};
            int j {cur.at(2)};
            if (i+1 < n && visit.at(i+1).at(j) == false) {
                minHeap.push({grid.at(i+1).at(j), i+1, j});
                visit.at(i+1).at(j) = true;
            }
            if (i-1 >= 0 && visit.at(i-1).at(j) == false) {
                minHeap.push({grid.at(i-1).at(j), i-1, j});
                visit.at(i-1).at(j) = true;
            }
            if (j+1 < n && visit.at(i).at(j+1) == false) {
                minHeap.push({grid.at(i).at(j+1), i, j+1});
                visit.at(i).at(j+1) = true;
            }
            if (j-1 >= 0 && visit.at(i).at(j-1) == false) {
                minHeap.push({grid.at(i).at(j-1), i, j-1});
                visit.at(i).at(j-1) = true;
            }
        }
        return res;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid {{0,2},{1,3}};
    // ans: 3
    // cout << sol.swimInWater_DFS(grid) << endl;
    cout << sol.swimInWater_Dijkstra(grid) << endl;

    grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    // ans: 16
    // cout << sol.swimInWater_DFS(grid) << endl;
    cout << sol.swimInWater_Dijkstra(grid) << endl;

    grid = {{35,19,17,25,4,10},{8,18,29,21,28,31},{15,5,33,2,13,3},{26,20,27,23,11,1},{6,14,24,7,12,16},{30,34,32,22,0,9}};
    // ans: 35
    // cout << sol.swimInWater_DFS(grid) << endl;
    cout << sol.swimInWater_Dijkstra(grid) << endl;

    grid = {{29,28,12,2,24,11},{17,30,25,9,13,33},{1,0,34,35,23,19},{31,22,4,26,6,3},{21,14,15,8,32,20},{5,18,7,27,16,10}};
    // ans: 29
    // cout << sol.swimInWater_DFS(grid) << endl;
    cout << sol.swimInWater_Dijkstra(grid) << endl;

    grid = {{3,19,34,15,7,21},{31,25,8,0,16,27},{4,1,13,18,28,17},{6,2,24,23,10,35},{20,5,22,12,32,29},{33,11,9,14,30,26}};
    // ans: 30
    // cout << sol.swimInWater_DFS(grid) << endl;
    cout << sol.swimInWater_Dijkstra(grid) << endl;

    grid = {{7,34,16,12,15,0},{10,26,4,30,1,20},{28,27,33,35,3,8},{29,9,13,14,11,32},{31,21,23,24,19,18},{22,6,17,5,2,25}};
    // ans: 26
    // cout << sol.swimInWater_DFS(grid) << endl;
    cout << sol.swimInWater_Dijkstra(grid) << endl;

    return 0;
}