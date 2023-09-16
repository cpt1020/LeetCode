#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

/*
g++ 1631.cpp -std=c++17 -o 1631 && ./1631
*/

auto comp = [](pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2) {
    return p1.first > p2.first;
};

class Solution {
private:

    vector<pair<int,int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<int>> &heights, vector<vector<bool>> &visit, const int &row, const int &col, int &mid, int r, int c) {
        if (r == row - 1 && c == col - 1) {
            return true;
        }
        visit.at(r).at(c) = true;

        for (auto const &dir : dirs) {
            int new_r {r + dir.first};
            int new_c {c + dir.second};

            if (new_r >= 0 && new_c >= 0 && new_r < row && new_c < col && abs(heights.at(new_r).at(new_c) - heights.at(r).at(c)) <= mid && visit.at(new_r).at(new_c) == false) {
                if (dfs(heights, visit, row, col, mid, new_r,new_c) == true) {
                    return true;
                }
            }
        }

        return false;
    }

public:

    int minimumEffortPath_DFS_BinarySearch(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights.at(0).size();
        int low {0}, high {heights.at(0).at(0)}, ans {0};

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                high = max(high, heights.at(i).at(j));
            }
        }

        while (low <= high) {
            int mid {(low+high)/2};
            vector<vector<bool>> visit (row, vector<bool>(col, false));
            if (dfs(heights, visit, row, col, mid, 0, 0)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int minimumEffortPath_Dijkstra(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights.at(0).size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(comp)> min_heap(comp);
        vector<vector<int>> dis (row, vector<int>(col, INT_MAX));
        dis.at(0).at(0) = 0;
        min_heap.push({0, {0, 0}});

        while (min_heap.empty() != true) {
            int distance {min_heap.top().first};
            int x {min_heap.top().second.first};
            int y {min_heap.top().second.second};
            min_heap.pop();
            if (x == row - 1 && y == col - 1) {
                return distance;
            }

            for (auto const &dir : dirs) {
                int new_x {x + dir.first};
                int new_y {y + dir.second};

                if (new_x < 0 || new_x >= row || new_y < 0 || new_y >= col) {
                    continue;
                }

                int new_d {max(abs(heights.at(new_x).at(new_y) - heights.at(x).at(y)), distance)};
                if (new_d < dis.at(new_x).at(new_y)) {
                    dis.at(new_x).at(new_y) = new_d;
                    min_heap.push({new_d, {new_x, new_y}});
                }
            }
        }

        return 0;

    }
};

int main() {

    Solution sol;

    vector<vector<int>> heights {{1,2,2},{3,8,2},{5,3,5}};
    // Output: 2
    cout << sol.minimumEffortPath_DFS_BinarySearch(heights) << endl;
    cout << sol.minimumEffortPath_Dijkstra(heights) << endl;

    heights = {{1,2,3},{3,8,4},{5,3,5}};
    // Output: 1
    cout << sol.minimumEffortPath_DFS_BinarySearch(heights) << endl;
    cout << sol.minimumEffortPath_Dijkstra(heights) << endl;

    heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    // Output: 0
    cout << sol.minimumEffortPath_DFS_BinarySearch(heights) << endl;
    cout << sol.minimumEffortPath_Dijkstra(heights) << endl;

    return 0;
}