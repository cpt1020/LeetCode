#include <iostream>
#include <string>
using namespace std;

/*
g++ 2864.cpp -std=c++17 -o 2864cpp && ./2864cpp
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones {0}, zeros {0};
        for (auto const &c : s) {
            if (c == '1') {
                ones += 1;
            }
            else {
                zeros += 1;
            }
        }
        
        string ans;
        
        for (int i {0}; i < ones - 1; ++i) {
            ans.push_back('1');
        }

        for (int i {0}; i < zeros; ++i) {
            ans.push_back('0');
        }

        ans.push_back('1');

        return ans;
    }
};

int main() {

    Solution sol;

    string s {"010"};
    // Output: "001"
    cout << sol.maximumOddBinaryNumber(s) << endl;

    s = "0101";
    // Output: "1001"
    cout << sol.maximumOddBinaryNumber(s) << endl;

    return 0;
}