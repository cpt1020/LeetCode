#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 621.cpp -std=c++17 -o 621 && ./621
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        for (auto t: tasks) {
            umap[t] += 1;
        }

        priority_queue<int> pq;
        for (auto key: umap) {
            pq.push(key.second);
        }

        int ans {0};
        while (pq.empty() != true) {
            int time {0};
            vector<int> tmp;

            for (int i {0}; i < (n + 1); ++i) {
                if (pq.empty() != true) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time += 1;
                }
            }
            
            for (auto num: tmp) {
                if (num - 1 > 0) {
                    pq.push(num - 1);
                }
            }

            if (pq.empty() != true) {
                ans += (n+1);
            }
            else {
                ans += time;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<char> tasks {'A','A','A','B','B','B'};
    int n {2};
    cout << sol.leastInterval(tasks, n) << endl;

    return 0;
}