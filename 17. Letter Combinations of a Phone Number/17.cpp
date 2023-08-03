#include <iostream>
#include <unordered_map>
#include <vector>
#include "../utils.h"
using namespace std;

// g++ 17.cpp ../utils.cpp -std=c++17 -o 17 && ./17

class Solution {
private:
    const vector<string> digit_to_char {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

public:

    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0) {
            return {};
        }

        vector<string> ans {""};

        for (const auto& num: digits) {
            vector<string> tmp;

            for (const auto& c: digit_to_char.at(num - '0')) {
                for (auto& str: ans) {
                    tmp.push_back(str + c);
                }
            }

            ans = tmp;
        }
        return ans;
    }
};

int main() {

    Solution sol;
    string digits {"23"};

    printVector<string>(sol.letterCombinations(digits));

    return 0;
}