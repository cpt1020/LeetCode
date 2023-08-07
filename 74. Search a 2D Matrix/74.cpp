#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix.at(0).size();
        int total = row * col;

        int left {0}, right {total - 1};
        int row_idx {0}, col_idx {0};

        while (left <= right) {
            int middle {(left + right)/2};

            row_idx = middle/col;
            col_idx = middle%col;

            if (matrix.at(row_idx).at(col_idx) == target) {
                return true;
            }
            else if (target < matrix.at(row_idx).at(col_idx)) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }

        }

        return false;
    }

};

int main() {

    Solution sol;

    vector<vector<int>> matrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target {3};
    // true
    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;

    matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    target = 13;
    // false
    cout << sol.searchMatrix(matrix, target) << endl;

    matrix = {{1},{3}};
    target = 3;
    // true
    cout << sol.searchMatrix(matrix, target) << endl;

    matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    target = 11;
    // true
    cout << sol.searchMatrix(matrix, target) << endl;

    matrix = {
        {-8,-6,-6,-4,-2,-1,-1,-1,0,1,2,4,6,7,7},
        {10,10,12,13,13,14,14,16,17,17,17,17,17,18,19},
        {22,24,26,28,29,31,32,34,34,34,34,36,38,39,39},
        {40,40,41,43,43,44,46,47,49,49,50,52,53,55,55},
        {56,57,59,61,62,64,65,65,66,67,68,68,69,70,71},
        {74,75,77,77,79,79,79,80,81,83,85,87,88,89,89},
        {91,93,94,96,97,98,99,99,100,100,102,104,105,107,107},
        {110,112,114,114,115,117,117,118,118,120,120,121,123,124,124},
        {127,127,129,131,133,134,134,135,137,139,139,140,142,143,144},
        {145,146,147,149,151,151,153,155,156,156,158,160,162,162,163}
    };
    target = 107;
    // true
    cout << sol.searchMatrix(matrix, target) << endl;

    return 0;
}