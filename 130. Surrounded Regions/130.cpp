#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 130.cpp ../utils.cpp -std=c++17 -o 130 && ./130
*/

class Solution {
private:

    void dfs(vector<vector<char>>& board, const int& row, const int& col, int i, int j) {
        board.at(i).at(j) = 'o';

        if (i + 1 < row && board.at(i+1).at(j) == 'O') {
            dfs(board, row, col, i+1, j);
        }
        if (i - 1 >= 0 && board.at(i-1).at(j) == 'O') {
            dfs(board, row, col, i-1, j);
        }
        if (j + 1 < col && board.at(i).at(j+1) == 'O') {
            dfs(board, row, col, i, j+1);
        }
        if (j - 1 >= 0 && board.at(i).at(j-1) == 'O') {
            dfs(board, row, col, i, j-1);
        }
    }

public:

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board.at(0).size();

        for (int i {0}; i < row; ++i) {
            if (board.at(i).at(0) == 'O') {
                dfs(board, row, col, i, 0);
            }
            if (board.at(i).at(col - 1) == 'O') {
                dfs(board, row, col, i, col - 1);
            }
        }

        for (int i {0}; i < col; ++i) {
            if (board.at(0).at(i) == 'O') {
                dfs(board, row, col, 0, i);
            }
            if (board.at(row - 1).at(i) == 'O') {
                dfs(board, row, col, row - 1, i);
            }
        }

        for (int i {0}; i < row; i++) {
            for (int j {0}; j < col; ++j) {
                if (board.at(i).at(j) != 'o') {
                    board.at(i).at(j) = 'X';
                }
                else {
                    board.at(i).at(j) = 'O';
                }
            }
        }
    }
};

int main() {

    Solution sol;

    vector<vector<char>> board {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    sol.solve(board);
    print2dVector<char>(board);

}