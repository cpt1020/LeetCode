#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/*
g++ 547.cpp -std=c++17 -o 547 && ./547
*/

class Solution {
private:

    int find(vector<int>& parent, int& n) {
        if (parent.at(n) != n) {
            parent.at(n) = find(parent, parent.at(n));
        }
        return parent.at(n);
    }

    void unionSet(vector<int>& parent, int& i, int& j, int& province) {
        int parent1 {find(parent, i)};
        int parent2 {find(parent, j)};

        if (parent1 != parent2) {
            parent.at(max(parent1, parent2)) = min(parent1, parent2);
            province -= 1;  // Do calculation of province here!
        }
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visit, const int& size, int& node) {
        visit.at(node) = true;

        for (int i {0}; i < size; ++i) {
            if (isConnected.at(node).at(i) == 1 && visit.at(i) == false) {
                dfs(isConnected, visit, size, i);
            }
        }
    }

public:

    int findCircleNum_UnionFind(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> parent (size, 0);
        for (int i {0}; i < size; ++i) {
            parent.at(i) = i;
        }

        int province {size};

        for (int i {0}; i < size; ++i) {
            for (int j {0}; j < size; ++j) {
                if (isConnected.at(i).at(j) == 1) {
                    unionSet(parent, i, j, province);
                }
            }
        }

        return province;
    }

    int findCircleNum_DFS(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<bool> visit (size, false);
        int province {0};

        for (int i {0}; i < size; ++i) {
            if (visit.at(i) == false) {
                dfs(isConnected, visit, size, i);
                province += 1;
            }
        }
        return province;
    }

    int findCircleNum_BFS(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<bool> visit (size, false);
        int province {0};

        queue<int> q;
        for (int i {0}; i < size; ++i) {
            if (visit.at(i) == false) {
                province += 1;
                q.push(i);
                visit.at(i) = true;

                while (q.empty() != true) {
                    int currNode {q.front()};
                    q.pop();

                    for (int j {0}; j < size; j++) {
                        if (isConnected.at(currNode).at(j) == 1 && visit.at(j) == false) {
                            visit.at(j) = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return province;
    }
};


int main() {

    Solution sol;

    vector<vector<int>> isConnected {{1,1,0},{1,1,0},{0,0,1}};
    // ans: 2
    cout << sol.findCircleNum_UnionFind(isConnected) << endl;
    cout << sol.findCircleNum_DFS(isConnected) << endl;
    cout << sol.findCircleNum_BFS(isConnected) << endl;

    isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    // ans: 3
    cout << sol.findCircleNum_UnionFind(isConnected) << endl;
    cout << sol.findCircleNum_DFS(isConnected) << endl;
    cout << sol.findCircleNum_BFS(isConnected) << endl;

    isConnected = {{1,0,0,0,1,0,1,0,0,0},{0,1,0,1,0,1,0,0,0,0},{0,0,1,0,0,1,0,0,0,0},{0,1,0,1,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,1,0},{0,1,1,0,0,1,1,0,0,0},{1,0,0,0,0,1,1,0,1,0},{0,0,0,0,0,0,0,1,0,0},{0,0,0,0,1,0,1,0,1,0},{0,0,0,0,0,0,0,0,0,1}};
    // ans: 3
    cout << sol.findCircleNum_UnionFind(isConnected) << endl;
    cout << sol.findCircleNum_DFS(isConnected) << endl;
    cout << sol.findCircleNum_BFS(isConnected) << endl;

    return 0;
}