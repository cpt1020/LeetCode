#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.size() == 1) {
            return false;
        }

        stack<char> st;

        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else if (st.empty() == true) {
                return false;
            }
            else if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{')) {
                return false;
            }
            else {
                st.pop();
            }
        }

        if (st.size() != 0) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {

    Solution sol;

    string s {"()[]{}"};
    cout << boolalpha << sol.isValid(s) << endl;

    s = "}[";
    cout << boolalpha << sol.isValid(s) << endl;

    s = "[}";
    cout << boolalpha << sol.isValid(s) << endl;

    return 0;
}