#include <iostream>
#include <vector>
#include <utility>
#include "../utils.h"
using namespace std;

/*
g++ 1222.cpp ../utils.cpp -std=c++17 -o 1222 && ./1222
*/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> chessboard (8, vector<int>(8, 0));
        for (const auto &queen : queens) {
            chessboard.at(queen.at(0)).at(queen.at(1)) = 1;
        }

        vector<vector<int>> ans;
        vector<int> found (8, 0);
        vector<pair<int,int>> dirs {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
        
        for (int i {1}; i <= 7; ++i) {
            for (int j {0}; j < 8; ++j) {
                if (found.at(j) == 0) {
                    int new_x = (dirs.at(j).first * i) + king.at(0);
                    int new_y = (dirs.at(j).second * i) + king.at(1);

                    if ((new_x < 0 || new_x > 7) || (new_y < 0 || new_y > 7)) {
                        found.at(j) = -1;
                        continue;
                    }

                    if (chessboard.at(new_x).at(new_y) == 1) {
                        ans.push_back({new_x, new_y});
                        found.at(j) = 1;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> queens {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king {0,0};
    print2dVector<int>(sol.queensAttacktheKing(queens, king));

    queens = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
    king = {3,3};
    print2dVector<int>(sol.queensAttacktheKing(queens, king));

    return 0;
}