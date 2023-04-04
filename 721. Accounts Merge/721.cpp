#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
g++ 721.cpp -std=c++17 -o 721 && ./721
*/

class Solution {
private:
    unordered_map<string, string> parent;
    // key: email, value: root email
    // 紀錄每個email的parent，也就是root mail
    // 這裡用root mail來代表set的root

    unordered_map<string, string> owner; 
    // key: email, value: owner name
    // 紀錄每個email的主人的name

    unordered_map<string, set<string>> group;
    // key: root email, value: set of emails
public:

    string FindSet(string str) {
        if (str != parent[str]) {
            parent[str] = FindSet(parent[str]);
            // 遞迴找到root email
        }
        return parent[str];
    }

    void Union(string x, string y) {
        x = parent[x];
        y = parent[y];
        if (x < y) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // 先把每個email的parent都設定成自己，並紀錄每個email的主人name
        for (auto acc: accounts) {
            for (int i {1}; i < acc.size(); ++i) {
                parent[acc.at(i)] = acc.at(i);
                // firstly, the owner of each email is itself
                owner[acc.at(i)] = acc.at(0);
            }
        }

        // 將同一個account的email的parent做設定
        for (auto acc: accounts) {
            for (int i {2}; i < acc.size(); ++i) {
                if (FindSet(acc.at(i - 1)) != FindSet(acc.at(i))) {
                    Union(acc.at(i - 1), acc.at(i));
                }
            }
        }

        // 找出每個email的root email，並將email insert到該root mail的set
        for (auto acc: accounts) {
            for (int i {1}; i < acc.size(); ++i) {
                string root_mail {FindSet(acc.at(i))};
                group[root_mail].insert(acc.at(i));
            }
        }

        vector<vector<string>> res;
        for (auto key: group) {
            vector<string> tmp;
            tmp.push_back(owner[key.first]);
            for (auto email: key.second) {
                tmp.push_back(email);
            }
            res.push_back(tmp);
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<vector<string>> accounts {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    vector<vector<string>> ans {sol.accountsMerge(accounts)};

    for (auto acc: ans) {
        for (auto data: acc) {
            cout << data << " ";
        }
        cout << endl;
    }

    return 0;
}