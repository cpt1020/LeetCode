#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
/*
    solution 1 (TLE encounterred, but get correct result)

    bool findWord(string s, vector<string>& wordDict, int& dictSize, int index) {

        if (index == s.size()){
            return true;
        }

        bool ans {false};
        for (int i {0}; i < dictSize; ++i) {
            string word {wordDict.at(i)};
            if (s.substr(index, word.size()) == word) {
                if (findWord(s, wordDict, dictSize, index + word.size()) == true) {
                    ans = true;
                }
            }
        }

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int dictSize {static_cast<int>(wordDict.size())};
        int index {0};

        return findWord(s, wordDict, dictSize, index);
    }
*/
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp (s.size()+1, false);
        dp.at(s.size()) = true;

        int word_size {1};
        for (int i {static_cast<int>(s.size()) - 1}; i >= 0; --i) {
            for (auto word: wordDict) {
                if ( i+word.size() <= s.size() && s.substr(i, word.size()) == word ) {
                    dp.at(i) = dp.at(i + word.size());
                }
                if (dp.at(i) == true){
                    break;
                }
            }
        }
        return dp.at(0);
    }
};

int main() {

    Solution sol;

    string s {"acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb"};
    vector<string> wordDict {"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"};
    cout << boolalpha << sol.wordBreak(s, wordDict) << endl;

    return 0;
}