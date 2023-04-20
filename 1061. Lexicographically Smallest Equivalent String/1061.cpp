#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1061.cpp -std=c++17 -o 1061 && ./1061
*/

class Solution {
public:

    char FindSet(unordered_map<char, char>& parent, char& c) {
        if (parent[c] != c) {
            parent[c] = FindSet(parent, parent[c]);
        }
        return parent[c];
    }

    void UnionSet(unordered_map<char, char>& parent, char& c1, char& c2) {
        char parent1 {FindSet(parent, c1)};
        char parent2 {FindSet(parent, c2)};

        if (parent1 != parent2) {
            parent[max(parent1, parent2)] = min(parent1, parent2);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, char> parent;

        for (char c {'a'}; c <= 'z'; ++c) {
            parent[c] = c;
        }

        for (int i {0}; i < s1.size(); ++i) {
            UnionSet(parent, s1.at(i), s2.at(i));
        }

        string ans;
        for (auto& c: baseStr) {
            if (parent.find(c) != parent.end()) {
                ans += FindSet(parent, c);
            }
            else {
                ans += c;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    cout << sol.smallestEquivalentString("hello", "world", "hold") << endl;
    cout << sol.smallestEquivalentString("parker", "morris", "parser") << endl;
    cout << sol.smallestEquivalentString("leetcode", "programs", "sourcecode") << endl;

    return 0;
}