#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 797.cpp ../utils.cpp -std=c++17 -o 797 && ./797
*/

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& tmp, int curNode) {
        tmp.push_back(curNode);
        if (curNode == graph.size() - 1) {
            ans.push_back(tmp);
            return;
        }

        for (int& n: graph.at(curNode)) {
            dfs(graph, ans, tmp, n);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(graph, ans, tmp, 0);
        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> graph {{1,2},{3},{3},{}};
    // Output: [[0,1,3],[0,2,3]]
    print2dVector<int>(sol.allPathsSourceTarget(graph));

    graph = {{1,3,4},{2,3,4},{3},{4},{}};
    // Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    print2dVector<int>(sol.allPathsSourceTarget(graph));

    return 0;
}