#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 54.cpp ../utils.cpp -std=c++17 -o 54 && ./54
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row {static_cast<int>(matrix.size())};
        int col {static_cast<int>(matrix.at(0).size())};
        
        int top {0};
        int left {0};
        int right {col-1};
        int bottom {row-1};
        int dir {0};

        while (left <= right && top <= bottom) {

            if (dir == 0) {
                for (int i {left}; i <= right; ++i) {
                    ans.push_back(matrix.at(top).at(i));
                }
                top++;
                dir = 1;
            }
            else if (dir == 1) {
                for (int i {top}; i <= bottom; ++i) {
                    ans.push_back(matrix.at(i).at(right));
                }
                right--;
                dir = 2;
            }
            else if (dir == 2) {
                for (int i {right}; i >= left; --i) {
                    ans.push_back(matrix.at(bottom).at(i));
                }
                bottom--;
                dir = 3;
            }
            else {
                for (int i {bottom}; i >= top; --i) {
                    ans.push_back(matrix.at(i).at(left));
                }
                left++;
                dir = 0;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> matrix {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printVector(sol.spiralOrder(matrix));

    return 0;
}