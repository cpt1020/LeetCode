#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
g++ 71.cpp -std=c++17 -o 71 && ./71
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        int i {0};
        while (i < path.size()) {
            if (path.at(i) != '/') {
                string tmp;
                int j {i};
                while (j < path.size() && path.at(j) != '/') {
                    tmp += path.at(j);
                    j++;
                }
                dirs.push_back(tmp);
                i = j + 1;
            }
            else {
                i++;
            }
        }

        stack<string> st;
        for (auto dir: dirs) {
            if (dir == "..") {
                if (st.size() != 0) {
                    st.pop();
                }
            }
            else if (dir == ".") {
                continue;
            }
            else {
                st.push(dir);
            }
        }

        if (st.empty() == true) {
            return "/";
        }

        string ans;
        while (st.empty() != true) {
            ans = st.top() + ans;
            ans = "/" + ans;
            st.pop();
        }

        return ans;
    }
};

int main() {

    Solution sol;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/home/") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/a//b////c/d//././/..") << endl;
    
    return 0;
}