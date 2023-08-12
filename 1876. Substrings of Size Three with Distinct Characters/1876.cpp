#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        size_t size {s.size()};
        if (size < 3) {
            return 0;
        }

        int alphabet [26] {0};
        alphabet [s.at(0) - 'a'] += 1;
        alphabet [s.at(1) - 'a'] += 1; 

        int ans {0};

        for (int i {2}; i < size; ++i) {
            if (i - 3 >= 0) {
                alphabet[s.at(i - 3) - 'a'] -= 1;
            }

            alphabet[s.at(i) - 'a'] += 1;

            if (alphabet[s.at(i) - 'a'] == 1 && alphabet[s.at(i - 1) - 'a'] == 1 && alphabet[s.at(i - 2) - 'a'] == 1) {
                ans += 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    string s {"xyzzaz"};
    // Output: 1
    cout << sol.countGoodSubstrings(s) << endl;

    s = "aababcabc";
    // Output: 4
    cout << sol.countGoodSubstrings(s) << endl;

    return 0;
}