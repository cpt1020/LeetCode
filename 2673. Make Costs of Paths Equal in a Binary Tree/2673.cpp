#include <vector>
#include <iostream>
using namespace std;

/*
g++ 2673.cpp -std=c++17 -o 2673 && ./2673
*/

class Solution {
private:
    int dfs(vector<int>& cost, const int& n, int i, int& ans) {
        if (i > n) {
            return 0;
        }
        
        int leftChildCost {dfs(cost, n, 2*i, ans)};
        int rightChildCost {dfs(cost, n, 2*i+1, ans)};
        
        ans += abs(leftChildCost - rightChildCost);
        
        return (max(leftChildCost, rightChildCost) + cost.at(i-1));
    }

public:
    int minIncrements(int n, vector<int>& cost) {        
        int ans {0};
        dfs(cost, n, 1, ans);
        return ans;
    }
};

int main() {

    Solution sol;

    int n {7};
    vector<int> cost {1,5,2,2,3,3,1};
    // Output: 6
    cout << sol.minIncrements(n, cost) << endl;

    n = 3;
    cost = {5,3,3};
    // Output: 0
    cout << sol.minIncrements(n, cost) << endl;

    n = 7;
    cost = {1,1,2,2,7,3,1};
    // Output: 10
    cout << sol.minIncrements(n, cost) << endl;

    return 0;
}