#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
g++ 392.cpp -std=c++17 -o 392cpp && ./392cpp
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char> sq, tq;
        for (const auto &c : s) {
            sq.push(c);
        }
        for (const auto &c : t) {
            tq.push(c);
        }

        while (sq.empty() != true && tq.empty() != true) {
            if (sq.front() == tq.front()) {
                sq.pop();
            }
            tq.pop();
        }

        return sq.empty();
    }
};

int main() {

    Solution sol;

    string s {"abc"};
    string t {"ahbgdc"};
    // Output: true
    cout << boolalpha << sol.isSubsequence(s, t) << endl;

    s = "axc";
    // Output: false
    cout << boolalpha << sol.isSubsequence(s, t) << endl;

    return 0;
}