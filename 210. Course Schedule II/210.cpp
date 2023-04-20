#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 210.cpp ../utils.cpp -std=c++17 -o 210 && ./210
*/

class Solution {
private:

    bool detectCycleDFS(vector<vector<int>>& graph, vector<int>& color, vector<int>& ans, int node) {
        bool res {false};
        color.at(node) = 1;

        for (auto n: graph.at(node)) {
            if (color.at(n) == 0) {
                if (detectCycleDFS(graph, color, ans, n) == true) {
                    res = true;
                }
                else {
                    if (find(ans.begin(), ans.end(), n) == ans.end()) {
                        ans.push_back(n);
                    }
                }
            }
            else if (color.at(n) == 1) { 
                res = true;
            }
        }
        color.at(node) = 2;
        return res;
    }

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) {
            vector<int> ans;
            for (int i {0}; i < numCourses; ++i) {
                ans.push_back(i);
            }
            return ans;
        }

        vector<vector<int>> graph (numCourses);
        for (auto vec: prerequisites) {
            graph.at(vec.at(0)).push_back(vec.at(1));
        }
        
        vector<int> ans;
        vector<int> color (numCourses, 0);

        for (int i {0}; i < graph.size(); ++i) {
            if (detectCycleDFS(graph, color, ans, i) == true) {
                return {};
            }
            else {
                if (find(ans.begin(), ans.end(), i) == ans.end()) {
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> prerequisites {{1,0}};
    printVector(sol.findOrder(2, prerequisites));

    prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    printVector(sol.findOrder(4, prerequisites));

    prerequisites = {};
    printVector(sol.findOrder(1, prerequisites));

    prerequisites = {{0,1}};
    printVector(sol.findOrder(2, prerequisites));

    return 0;
}