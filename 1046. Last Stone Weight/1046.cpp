#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1046.cpp -std=c++17 -o 1046 && ./1046
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int s: stones) {
            pq.push(s);
        }

        while (pq.size() > 1) {
            int x {pq.top()};
            pq.pop();
            int y {pq.top()};
            pq.pop();

            if (x != y) {
                pq.push(x-y);
            }
        }

        return pq.size() == 0? 0: pq.top();
    }
};

int main() {

    Solution sol;

    vector<int> stones {2,7,4,1,8,1};
    // ans: 1
    cout << sol.lastStoneWeight(stones) << endl;

    stones = {1};
    // ans: 1
    cout << sol.lastStoneWeight(stones) << endl;

    return 0;
}