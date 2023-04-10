#include <vector>
#include <queue>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 973.cpp ../utils.cpp -std=c++17 -o 973 && ./973
*/

auto cmp = [](vector<int>& a, vector<int>& b) {
    return (a.at(0)*a.at(0) + a.at(1)*a.at(1)) > (b.at(0)*b.at(0) + b.at(1)*b.at(1));
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto pair: points) {
            pq.push(pair);
        }

        vector<vector<int>> res;
        for (int i {0}; i < k; ++i) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};

int main(){

    Solution sol;

    // case 1
    cout << "case 1" << endl;
    vector<vector<int>> points {{3,3},{5,-1},{-2,4}};
    // ans: [[3,3],[-2,4]]
    print2dVector(sol.kClosest(points, 2));

    // case 2
    cout << "\ncase 2" << endl;
    points = {{1,3},{-2,2}};
    // ans: [[-2,2]]
    print2dVector(sol.kClosest(points, 1));

    return 0;
}