#include <utility>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 2492.cpp -std=c++17 -o 2492 && ./2492
*/

class Solution {
private:

    int findSet(vector<pair<int, int>>& parent, int& i) {
        if (i != parent.at(i).first) {
            parent.at(i).first = findSet(parent, parent.at(i).first);
        }
        return parent.at(i).first;
    }

    void unionSet(vector<pair<int, int>>& parent, int& i, int& j, int& d) {
        int parent1 {findSet(parent, i)};
        int parent2 {findSet(parent, j)};

        int distance = min({parent.at(parent1).second, parent.at(parent2).second, d});
        parent.at(parent1).second = parent.at(parent2).second = distance;

        if (parent1 != parent2) {
            parent.at(max(parent1, parent2)).first = min(parent1, parent2);
        }
    }

public:

    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> parent (n+1);
        // first value is root parent, second value is distance
        for (int i {0}; i < n+1; ++i) {
            parent.at(i) = {i, INT_MAX};
        }

        for (int i {0}; i < roads.size(); ++i) {
            unionSet(parent, roads.at(i).at(0), roads.at(i).at(1), roads.at(i).at(2));
        }

        return parent.at(1).second;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> roads {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    // ans: 5
    cout << sol.minScore(4, roads) << endl;

    roads = {{1,2,2},{1,3,4},{3,4,7}};
    // ans: 2
    cout << sol.minScore(4, roads) << endl;

    return 0;
}