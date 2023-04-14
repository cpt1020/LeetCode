#include <vector>
#include <iostream>
using namespace std;

/*
g++ 516.cpp -std=c++17 -o 516 && ./516
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp (s.size(), vector<int>(s.size()));

        for (int i = s.size() - 1; i >= 0; --i) {
            dp.at(i).at(i) = 1;
            for (int j {i+1}; j < s.size(); ++j) {
                if (s.at(i) == s.at(j)) {
                    dp.at(i).at(j) = dp.at(i+1).at(j-1) + 2;
                }
                else {
                    dp.at(i).at(j) = max(dp.at(i).at(j-1), dp.at(i+1).at(j));
                }
            }
        }

        return dp.at(0).at(s.size()-1);
    }
};

int main() {

    Solution sol;

    cout << sol.longestPalindromeSubseq("bbbab") << endl;
    cout << sol.longestPalindromeSubseq("cbbd") << endl;

    return 0;
}