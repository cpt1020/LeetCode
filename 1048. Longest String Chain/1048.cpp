#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });

        unordered_map<string, int> dp;
        int ans {0};
        for (auto &str: words) {
            for (int i {0}; i < str.size(); ++i) {
                string previous {str.substr(0, i) + str.substr(i + 1)};
                dp[str] = max(dp[str], dp.find(previous) == dp.end() ? 1 : dp[previous] + 1);
            }
            ans = max(ans, dp[str]);
        }
        return ans;
    }
};

int main() {

    Solution sol;

    vector<string> words {"a","b","ba","bca","bda","bdca"};
    // Output: 4
    cout << sol.longestStrChain(words) << endl;

    words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    // Output: 5
    cout << sol.longestStrChain(words) << endl;

    words = {"abcd","dbqca"};
    // Output: 1
    cout << sol.longestStrChain(words) << endl;

    return 0;
}