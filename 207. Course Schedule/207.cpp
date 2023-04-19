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
};

int main(){

    Solution sol;

    vector<vector<int>> prerequisites {{1,0}};
    cout << boolalpha << sol.canFinish(2, prerequisites) << endl;

    prerequisites = {{1,0}, {0,1}};
    cout << boolalpha << sol.canFinish(2, prerequisites) << endl;

    return 0;
}