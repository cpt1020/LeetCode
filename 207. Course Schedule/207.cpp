#include <iostream>
#include <vector>
using namespace std;

/*
g++ 207.cpp -std=c++17 -o 207 && ./207
*/

class Solution {
private:

    bool detectCycleDFS(vector<vector<int>>& graph, vector<int>& color, int i){
        bool result {false};
        // we should use this result to control what to return!

        color.at(i) = 1;
        for (int num: graph.at(i)){
            if (color.at(num) == 0){

                // notice this if statement
                if (detectCycleDFS(graph, color, num) == true){
                    result = true;
                }
            }
            else if (color.at(num) == 1){
                result = true;
            }
        }
        color.at(i) = 2;
        return result;
    }

public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0 || prerequisites.size() == 1){
            return true;
        }
        vector<vector<int>> graph (numCourses);
        for (int i {0}; i < prerequisites.size(); ++i){
            graph.at(prerequisites.at(i).at(1)).push_back(prerequisites.at(i).at(0));
        }

        vector<int> color (numCourses, 0);
        
        for (int i {0}; i < graph.size(); ++i){
            if (graph.at(i).size() != 0 && color.at(i) == 0){
                if (detectCycleDFS(graph, color, i) == true){
                    return false;
                }
            }
        }
        return true;
    }

    bool canFinish_BFS(int numCourses, vector<vector<int>>& prerequisites) {
    // using topological sort
        if (prerequisites.size() == 0 || prerequisites.size() == 1){
            return true;
        }
        vector<vector<int>> graph (numCourses);
        for (int i {0}; i < prerequisites.size(); ++i){
            graph.at(prerequisites.at(i).at(1)).push_back(prerequisites.at(i).at(0));
        }

        vector<int> in_degree (numCourses, 0);
        for (auto node: graph) {
            for (auto adj_n: node) {
                in_degree.at(adj_n) += 1;
            }
        }
        
        for (int i {0}; i < numCourses; ++i){
            int j {0};
            for (; j < numCourses; ++j) {
                if (in_degree.at(j) == 0) {
                    break;
                }
            }

            if (j == numCourses) {
                return false;
            }

            in_degree.at(j) -= 1;

            for (auto n: graph.at(j)) {
                in_degree.at(n) -= 1;
            }
        }
        return true;
    }
};

int main(){

    Solution sol;

    vector<vector<int>> prerequisites {{1,0}};
    cout << boolalpha << sol.canFinish(2, prerequisites) << endl;
    cout << boolalpha << sol.canFinish_BFS(2, prerequisites) << endl;

    prerequisites = {{1,0}, {0,1}};
    cout << boolalpha << sol.canFinish(2, prerequisites) << endl;
    cout << boolalpha << sol.canFinish_BFS(2, prerequisites) << endl;

    prerequisites = {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
    cout << boolalpha << sol.canFinish(20, prerequisites) << endl;
    cout << boolalpha << sol.canFinish_BFS(20, prerequisites) << endl;

    prerequisites = {{1,4},{2,4},{3,1},{3,2}};
    cout << boolalpha << sol.canFinish(5, prerequisites) << endl;
    cout << boolalpha << sol.canFinish_BFS(5, prerequisites) << endl;

    return 0;
}