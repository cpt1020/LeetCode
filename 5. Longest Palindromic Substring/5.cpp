#include <string>
#include <iostream>
using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {
        if (s.size() == 1){
            return s;
        }

        string ans;

        for (int i {0}; i < s.size(); i++) {

            // for odd length palindrome substring
            int left {i}, right {i};
            while (left >= 0 && right < s.size() && s.at(left) == s.at(right)){
                if ((right - left + 1) > ans.size()) {
                    ans = s.substr(left, right-left+1);
                }
                left-=1;
                right+=1;
            }

            // for even length palindrome substring
            left = i;
            right = i+1;
            while (left >= 0 && right < s.size() && s.at(left) == s.at(right)){
                if ((right - left + 1) > ans.size()) {
                    ans = s.substr(left, right-left+1);
                }
                left-=1;
                right+=1;
            }
        }
        return ans;
    }
};

int main(){

    string s {"babad"};
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;

    return 0;
}