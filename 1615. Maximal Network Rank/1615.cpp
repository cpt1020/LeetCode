#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
g++ 1615.cpp -std=c++17 -o 1615 && ./1615
*/

class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if (roads.size() == 0) {
            return 0;
        }

        vector<unordered_set<int>> connected_city (n);
        for (auto &road: roads) {
            connected_city.at(road.at(0)).insert(road.at(1));
            connected_city.at(road.at(1)).insert(road.at(0));
        }

        int ans {0};

        for (int i {0}; i < n - 1; ++i) {
            for (int j {i + 1}; j < n; ++j) {
                int size = connected_city.at(i).size() + connected_city.at(j).size();
                if (connected_city.at(i).find(j) != connected_city.at(i).end()) {
                    size -= 1;
                }
                ans = max(ans, size);
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> roads {{0,1},{0,3},{1,2},{1,3}};
    int n {4};
    // Output: 4
    cout << sol.maximalNetworkRank(n, roads) << endl;

    roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    n = 5;
    // Output: 5
    cout << sol.maximalNetworkRank(n, roads) << endl;

    roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    n = 8;
    // Output: 5
    cout << sol.maximalNetworkRank(n, roads) << endl;

    return 0;
}