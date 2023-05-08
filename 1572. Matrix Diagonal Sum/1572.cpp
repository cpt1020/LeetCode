#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1572.cpp -std=c++17 -o 1572 && ./1572
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans {0};
        int m = mat.size();

        for (int i {0}; i < m; ++i) {
            ans += mat.at(i).at(i);
            if (m-1-i != i) {
                ans += mat.at(i).at(m-1-i);
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> mat {{1,2,3},
                             {4,5,6},
                             {7,8,9}};
    // Output: 25
    cout << sol.diagonalSum(mat) << endl;

    mat = {{1,1,1,1},
           {1,1,1,1},
           {1,1,1,1},
           {1,1,1,1}};
    // Output: 8
    cout << sol.diagonalSum(mat) << endl;
    
    mat = {{5}};
    // Output: 5
    cout << sol.diagonalSum(mat) << endl;

    return 0;
}