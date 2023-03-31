#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:

    const vector<string> dig {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

public:

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return {};
        }

        vector<string> ans {""};

        for (auto digit: digits) {
            vector<string> tmp;
            for (auto c: dig.at(digit - '0')) {
                for (auto s: ans) {
                    tmp.push_back(s + c);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};

int main(){

    string digits {"23"};
    Solution sol;
    vector<string> ans {sol.letterCombinations(digits)};
    for (auto s: ans){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}