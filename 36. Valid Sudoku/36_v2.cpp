#include <vector>
#include <iostream>
using namespace std;

/*
g++ 36_v2.cpp -std=c++17 -o 36_v2 && ./36_v2
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row (9, vector<bool>(10, false));
        vector<vector<bool>> col (9, vector<bool>(10, false));
        vector<vector<bool>> box (9, vector<bool>(10, false));

        for (int r {0}; r < 9; r++) {
            for (int c {0}; c < 9; c++) {
                if (board.at(r).at(c) != '.') {
                    if (row.at(r).at(board.at(r).at(c) - '0') == true ||
                        col.at(c).at(board.at(r).at(c) - '0') == true ||
                        box.at( (r/3)*3 + (c/3) ).at(board.at(r).at(c) - '0') == true) {
                        return false;
                    }
                    else {
                        row.at(r).at(board.at(r).at(c) - '0') = true;
                        col.at(c).at(board.at(r).at(c) - '0') = true;
                        box.at( (r/3)*3 + (c/3) ).at(board.at(r).at(c) - '0') = true;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board {
        {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };
    
    Solution sol;

    cout << boolalpha << sol.isValidSudoku(board) << endl;

    return 0;
}