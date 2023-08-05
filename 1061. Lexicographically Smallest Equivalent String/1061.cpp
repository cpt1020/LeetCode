#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1061.cpp -std=c++17 -o 1061 && ./1061
*/

class Solution {
public:

    char FindSet(char *parent, char& c) {
    // char FindSet(char parent [], char& c) {
        if (parent[c - 'a'] != c) {
            parent[c - 'a'] = FindSet(parent, parent[c - 'a']);
        }

        return parent[c - 'a'];
    }

    void UnionSet(char *parent, char& s1, char& s2) {
    // void UnionSet(char parent [], char& s1, char& s2) {
        char parent1 {FindSet(parent, s1)};
        char parent2 {FindSet(parent, s2)};

        if (parent1 != parent2) {
            parent[max(parent1, parent2) - 'a'] = min(parent1, parent2);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char parent [26];

        for (int i {0}; i < 26; ++i) {
            parent[i] = i + 'a';
        }

        for (int i {0}; i < s1.size(); ++i) {
            UnionSet(parent, s1.at(i), s2.at(i));
        }

        // 做最後一次
        for (char c {'a'}; c <= 'z'; ++c) {
            parent[c - 'a'] = FindSet(parent, parent[c - 'a']);
        }

        string ans;
        for (const auto& c : baseStr) {
            ans += parent[c  - 'a'];
        }

        return ans;
    }

    // char FindSet(unordered_map<char, char>& parent, char& c) {
    //     if (parent[c] != c) {
    //         parent[c] = FindSet(parent, parent[c]);
    //     }
    //     return parent[c];
    // }

    // void UnionSet(unordered_map<char, char>& parent, char& c1, char& c2) {
    //     char parent1 {FindSet(parent, c1)};
    //     char parent2 {FindSet(parent, c2)};

    //     if (parent1 != parent2) {
    //         parent[max(parent1, parent2)] = min(parent1, parent2);
    //     }
    // }

    // string smallestEquivalentString(string s1, string s2, string baseStr) {
    //     unordered_map<char, char> parent;

    //     for (char c {'a'}; c <= 'z'; ++c) {
    //         parent[c] = c;
    //     }

    //     for (int i {0}; i < s1.size(); ++i) {
    //         UnionSet(parent, s1.at(i), s2.at(i));
    //     }

    //     string ans;
    //     for (auto& c: baseStr) {
    //         if (parent.find(c) != parent.end()) {
    //             ans += FindSet(parent, c);
    //         }
    //         else {
    //             ans += c;
    //         }
    //     }

    //     return ans;
    // }
};

int main() {

    Solution sol;

    cout << sol.smallestEquivalentString("hello", "world", "hold") << endl;
    // "hdld"
    cout << sol.smallestEquivalentString("parker", "morris", "parser") << endl;
    // "makkek"
    cout << sol.smallestEquivalentString("leetcode", "programs", "sourcecode") << endl;
    // "aauaaaaada"

    return 0;
}