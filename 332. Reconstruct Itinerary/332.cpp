#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include "../utils.h"
using namespace std;

/*
g++ 332.cpp ../utils.cpp -std=c++20 -o 332 && ./332
*/

auto comp = [](string &str1, string &str2) {
    for (int i {0}; i < 3; ++i) {
        if (str1.at(i) != str2.at(i)) {
            return str1.at(i) > str2.at(i);
        }
    }
    return true;
};

class Solution {
public:

    void dfs(unordered_map<string, priority_queue<string, vector<string>, decltype(comp)>> &umap, string departure, vector<string> &ans) {

        while (umap[departure].empty() != true) {
            string arr {umap[departure].top()};
            umap[departure].pop();
            dfs(umap, arr, ans);
        }
        ans.push_back(departure);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, decltype(comp)>> umap;
        for (const auto &vec : tickets) {
            umap[vec.at(0)].push(vec.at(1));
        }

        vector<string> ans;
        dfs(umap, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<string>> tickets {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    // Output: ["JFK","MUC","LHR","SFO","SJC"]
    printVector<string>(sol.findItinerary(tickets));

    tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    printVector<string>(sol.findItinerary(tickets));

    tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    // Output: ["JFK","NRT","JFK","KUL"]
    printVector<string>(sol.findItinerary(tickets));

    return 0;
}