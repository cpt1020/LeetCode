#include <vector>
#include <iostream>
using namespace std;

/*
g++ 36.cpp -std=c++17 -o 36 && ./36
*/

class Solution {
public:

    bool checkRow(vector<vector<char>>& board) {
        for (int i {0}; i < 9; ++i) {
            vector<int> num (10, 0);
            for (int j {0}; j < 9; ++j) {
                if (board.at(i).at(j) != '.') {
                    num.at(board.at(i).at(j) - '0') += 1;
                }
            }

            for (auto n: num) {
                if (n > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board) {
        for (int i {0}; i < 9; ++i) {
            vector<int> num (10, 0);
            for (int j {0}; j < 9; ++j) {
                if (board.at(j).at(i) != '.') {
                    num.at(board.at(j).at(i) - '0') += 1;
                }
            }

            for (auto n: num) {
                if (n > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkSubbox(vector<vector<char>>& board) {
        for (int i {0}; i < 7; i += 3) {
            
            for (int j {0}; j < 7; j += 3) {

                vector<int> num (10, 0);

                for (int k {i}; k < (i+3); ++k) {
                    for (int l {j}; l < (j+3); ++l) {
                        if (board.at(k).at(l) != '.') {
                            num.at(board.at(k).at(l) - '0') += 1;
                        }
                    }
                }

                for (auto n: num) {
                    if (n > 1) {
                        return false;
                    }
                }
            }
        }
        return true;

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRow(board) && checkCol(board) && checkSubbox(board);
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