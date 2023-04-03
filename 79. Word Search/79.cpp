#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int i, int j, int n, int row, int col) {
        if (n == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= row || j >= col || board.at(i).at(j) != word.at(n) || visit.at(i).at(j) == true) {
            return false;
        }

        visit.at(i).at(j) = true;

        bool res {dfs(board, word, visit, i + 1, j, n + 1, row, col) ||
                  dfs(board, word, visit, i - 1, j, n + 1, row, col) ||
                  dfs(board, word, visit, i, j + 1, n + 1, row, col) ||
                  dfs(board, word, visit, i, j - 1, n + 1, row, col)};
        
        // key point step!!!
        visit.at(i).at(j) = false;
        return res;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int row {static_cast<int>(board.size())};
        int col {static_cast<int>(board.at(0).size())};

        if (word.size() > row * col) {
            return false;
        }

        vector<vector<bool>> visit (row, vector<bool>(col, false));
        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (board.at(i).at(j) == word.at(0) && dfs(board, word, visit, i, j, 0, row, col)) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {

    Solution sol;

    vector<vector<char>> board {
        {'C','A','A'},
        {'A','A','A'},
        {'B','C','D'}
    };

    cout << boolalpha << sol.exist(board, "AAB") << endl;

    return 0;
}