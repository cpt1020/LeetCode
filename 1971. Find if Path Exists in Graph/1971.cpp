#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

/*
g++ 1971.cpp -std=c++17 -o 1971 && ./1971
*/

class Solution {
// DFS solution
private:

    void dfs(unordered_map<int, vector<int>>& umap, const int& destination, bool& res, const int& node, vector<bool>& visit) {
        visit.at(node) = true;
        if (node == destination) {
            res = true;
            return;
        }

        for (auto n: umap[node]) {
            if (visit.at(n) == false) {
                dfs(umap, destination, res, n, visit); 
            }
        }
        return;
    }

public:

    bool validPath_DFS(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) {
            return true;
        }

        unordered_map<int, vector<int>> umap;
        for (auto& edge: edges) {
            umap[edge.at(0)].push_back(edge.at(1));
            umap[edge.at(1)].push_back(edge.at(0));
        }

        bool res {false};
        vector<bool> visit (n, false);
        for (auto& node: umap[source]) {
            if (visit.at(node) == false) {
                dfs(umap, destination, res, node, visit);
            }
        }
        return res;
    }

// BFS solution
    bool validPath_BFS(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) {
            return true;
        }

        unordered_map<int, vector<int>> umap;
        for (auto& edge: edges) {
            umap[edge.at(0)].push_back(edge.at(1));
            umap[edge.at(1)].push_back(edge.at(0));
        }

        vector<bool> visit (n, false);
        queue<int> q;
        q.push(source);
        visit.at(source) = true;

        while (q.empty() != true) {
            int currV {q.front()};
            q.pop();
            if (currV == destination) {
                return true;
            }

            for (auto& n: umap[currV]) {
                if (visit.at(n) == false) {
                    visit.at(n) = true;
                    q.push(n);
                }
            }
        }

        return false;
    }

// Union Find solution
private:

    int FindSet(const int& n, vector<int>& parent) {
        if (parent.at(n) == n) {
            return n;
        }
        else {
            parent.at(n) = FindSet(parent.at(n), parent);
            return parent.at(n);
        }
    }

    void Union(vector<int>& parent, const int& n1, const int& n2) {
        int parent1 = FindSet(n1, parent);
        int parent2 = FindSet(n2, parent);
        parent.at(parent1) = parent2;
    }

public:

    bool validPath_UnionFind(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent (n);
        for (int i {0}; i < n; ++i) {
            parent.at(i) = i;
        }

        for (auto edge: edges) {
            Union(parent, edge.at(0), edge.at(1));
        }

        return (FindSet(source, parent) == FindSet(destination, parent));

    }
};

int main() {

    Solution sol;

    vector<vector<int>> edges {{0,1},{1,2},{2,0}};
    cout << boolalpha << sol.validPath_DFS(3, edges, 0, 2) << endl;
    cout << boolalpha << sol.validPath_BFS(3, edges, 0, 2) << endl;
    cout << boolalpha << sol.validPath_UnionFind(3, edges, 0, 2) << endl;

    edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    cout << boolalpha << sol.validPath_DFS(6, edges, 0, 5) << endl;
    cout << boolalpha << sol.validPath_BFS(6, edges, 0, 5) << endl;
    cout << boolalpha << sol.validPath_UnionFind(6, edges, 0, 5) << endl;

    edges = {{41,40},{9,32},{48,14},{6,44},{18,41},{41,1},{7,41},{38,41},{19,4},{16,41},{41,43},{41,22},{41,21},{9,0},{41,48},{32,36},{24,44},{39,41},{48,17},{49,15},{47,41},{19,31},{11,41},{41,23},{41,49},{45,44},{2,49},{13,41},{35,41},{30,0},{5,44},{8,0},{41,20},{41,28},{12,11},{12,41},{49,10},{19,0},{0,37},{34,41},{42,48},{27,41},{0,41},{19,44},{41,26},{41,29},{33,41},{49,46},{41,25},{3,41}};
    cout << boolalpha << sol.validPath_DFS(50, edges, 40, 3) << endl;
    cout << boolalpha << sol.validPath_BFS(50, edges, 40, 3) << endl;
    cout << boolalpha << sol.validPath_UnionFind(50, edges, 40, 3) << endl;

    edges = {{96,56},{6,96},{64,13},{40,39},{77,37},{84,77},{49,73},{16,24},{40,94},{71,95},{16,38},{10,36},{92,90},{44,33},{94,9},{44,90},{2,90},{93,69},{96,25},{29,86},{64,45},{91,14},{96,87},{4,62},{94,65},{18,96},{16,90},{5,12},{14,94},{0,3},{22,96},{49,96},{71,17},{63,17},{29,84},{33,90},{91,26},{15,74},{89,86},{8,48},{25,72},{55,96},{54,52},{75,48},{78,79},{90,38},{90,27},{50,25},{0,9},{60,15},{56,66},{31,55},{66,89},{3,72},{80,90},{1,90},{96,95},{49,70},{36,96},{96,70},{21,90},{84,91},{33,97},{90,42},{76,90},{67,96},{47,64},{90,86},{72,76},{59,90},{96,82},{21,63},{47,96},{33,24},{11,25},{44,14},{5,94},{19,34},{96,69},{88,60},{47,6},{74,83},{68,90},{96,93},{97,78},{31,74},{53,96},{63,59},{92,54},{94,35},{90,64},{72,96},{74,96},{15,96},{78,29},{37,57},{23,0},{37,90},{99,63},{96,85},{20,90},{90,54},{96,30},{90,98},{73,76},{66,90},{99,61},{95,30},{96,63},{52,97},{16,10},{96,4},{96,19},{16,96},{78,64},{8,62},{87,34},{64,26},{27,87},{81,90},{83,90},{19,74},{13,96},{80,64},{49,11},{31,90},{96,23},{96,41},{0,34},{72,75},{57,32},{15,91},{71,90},{96,92},{79,90},{97,48},{58,96},{96,17},{4,2},{51,91},{51,0},{61,79},{75,15},{95,89},{70,88},{57,0},{7,96},{8,90},{88,8},{39,96},{77,90},{46,90},{37,11},{88,14},{12,8},{96,12},{96,62},{45,18},{90,50},{8,97},{75,96},{38,53},{96,99},{89,96},{89,40},{34,73},{96,11},{94,3},{37,41},{90,3},{88,96},{94,32},{45,90},{43,12},{56,64},{73,7},{42,48},{83,9},{96,29},{81,12},{91,90},{90,28},{96,97},{44,79},{96,43},{27,21},{24,52},{68,18},{20,8},{34,7},{25,83},{58,6},{93,80},{16,0},{59,5},{21,78},{55,78},{60,96},{26,0},{44,99}};
    cout << boolalpha << sol.validPath_DFS(100, edges, 53, 18) << endl;
    cout << boolalpha << sol.validPath_BFS(100, edges, 53, 18) << endl;
    cout << boolalpha << sol.validPath_UnionFind(100, edges, 53, 18) << endl;

    return 0;
}