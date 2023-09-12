#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

auto comp = [](pair<int, char> p1, pair<int, char> p2) {
    return p1.first < p2.first;
};

class Solution {
public:

    int minDeletions_max_heap(string s) {
        int alphabet [26] = {0};
        for (const auto &c : s) {
            *(alphabet + (c - 'a')) += 1;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> max_heap(comp);
        for (int i {0}; i < 26; ++i) {
            if (*(alphabet + i) != 0) {
                max_heap.push({*(alphabet + i), 'a' + i});
            }
        }

        int prev_freq {INT_MAX};
        int ans {0};
        while (max_heap.empty() != true) {
            if (max_heap.top().first == prev_freq) {
                pair<int, char> tmp {max_heap.top()};
                max_heap.pop();
                if (tmp.first != 0) {
                    max_heap.push({tmp.first - 1, tmp.second});
                    ans += 1;
                }
            }
            else {
                prev_freq = max_heap.top().first;
                max_heap.pop();
            }
        }

        return ans;
    }

    int minDeletions_unordered_set(string s) {
        int alphabet [26] = {0};
        for (const auto &c : s) {
            *(alphabet + (c - 'a')) += 1;
        }

        unordered_set<int> uset;
        int ans {0};
        for (int i {0}; i < 26; ++i) {
            if (*(alphabet + i) != 0) {
                while (uset.find(*(alphabet + i)) != uset.end()) {
                    *(alphabet + i) -= 1;
                    ans += 1;
                    if (*(alphabet + i) == 0) {
                        break;
                    }
                }
                uset.insert(*(alphabet + i));
            }
        }
        return ans;
    }
};

int main() {

    Solution sol;

    string s {"aab"};
    cout << sol.minDeletions_max_heap(s) << endl;
    cout << sol.minDeletions_unordered_set(s) << endl;

    s = "aaabbbcc";
    cout << sol.minDeletions_max_heap(s) << endl;
    cout << sol.minDeletions_unordered_set(s) << endl;

    s = "ceabaacb";
    cout << sol.minDeletions_max_heap(s) << endl;
    cout << sol.minDeletions_unordered_set(s) << endl;

    return 0;
}