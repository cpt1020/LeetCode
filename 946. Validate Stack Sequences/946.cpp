#include <stack>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 946.cpp -std=c++17 -o 946 && ./946
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i {0};

        for (auto n: pushed) {
            st.push(n);
            while (st.size() > 0 && st.top() == popped.at(i)) {
                st.pop();
                i++;
            }
        }

        return st.size() == 0;
    }
};

int main() {

    Solution sol;

    vector<int> pushed {1,2,3,4,5};
    vector<int> popped {4,5,3,2,1};
    cout << boolalpha << sol.validateStackSequences(pushed, popped) << endl;

    popped = {4,3,5,1,2};
    cout << boolalpha << sol.validateStackSequences(pushed, popped) << endl;

    return 0;
}