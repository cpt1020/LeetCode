#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
g++ 2390.cpp -std=c++17 -o 2390 && ./2390
*/

class Solution {
public:
    string removeStars(string s) {        
        stack<char> st;
        for (auto c: s) {
            if (c != '*') {
                st.push(c);
            }
            else {
                st.pop();
            }
        }
        string ans;
        while (st.empty() != true) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string removeStars_optimizedVer(string s) {
        string ans;
        for (auto c : s) {
            if (c == '*') {
                ans.pop_back();
            }
            else {
                ans += c;
            }
        }
        return ans;
    }
};

int main() {

    Solution sol;
    string s {"leet**cod*e"};
    // ans: "lecoe"
    cout << sol.removeStars(s) << endl;
    cout << sol.removeStars_optimizedVer(s) << endl;

    s = "erase*****";
    // ans: ""
    cout << sol.removeStars(s) << endl;
    cout << sol.removeStars_optimizedVer(s) << endl;

    return 0;
}