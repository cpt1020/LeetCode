#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
g++ 1456.cpp -std=c++17 -o 1456 && ./1456
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');

        int ans {0};
        for (int i {0}; i < k; ++i) {
            if (vowel.find(s.at(i)) != vowel.end()) {
                ans += 1;
            }
        }

        int i {0}, j {k};
        int vowelCnt {ans};
        while (j < s.size()) {
            if (vowel.find(s.at(j)) != vowel.end()) {
                vowelCnt += 1;
            }
            if (vowel.find(s.at(i)) != vowel.end()) {
                vowelCnt -= 1;
            }

            ans = max(ans, vowelCnt);
            i++;
            j++;
        }

        return ans;
    }
};

int main() {

    Solution sol;

    string s {"leetcode"};
    int k {3};
    // Output: 2
    cout << sol.maxVowels(s, k) << endl;

    s = "abciiidef";
    k = 3;
    // Output: 3
    cout << sol.maxVowels(s, k) << endl;

    s = "aeiou";
    k = 2;
    // Output: 2
    cout << sol.maxVowels(s, k) << endl;

    return 0;
}