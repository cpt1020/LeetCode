#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include "../utils.h"
using namespace std;

/*
g++ 542.cpp ../utils.cpp -std=c++17 -o 542 && ./542
*/

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat.at(0).size();

        queue<pair<int, int>> q;

        for (int i {0}; i < row; ++i) {
            for (int j {0}; j < col; ++j) {
                if (mat.at(i).at(j) == 0) {
                    q.push({i, j});
                }
                else {
                    mat.at(i).at(j) = -1;
                }
            }
        }

        while (q.empty() != true) {
            int r {q.front().first};
            int c {q.front().second};
            q.pop();

            if (r + 1 < row && mat.at(r+1).at(c) == -1) {
                q.push({r+1, c});
                mat.at(r+1).at(c) = mat.at(r).at(c) + 1;
            }
            if (r - 1 >= 0 && mat.at(r-1).at(c) == -1) {
                q.push({r-1, c});
                mat.at(r-1).at(c) = mat.at(r).at(c) + 1;
            }
            if (c + 1 < col && mat.at(r).at(c+1) == -1) {
                q.push({r, c+1});
                mat.at(r).at(c+1) = mat.at(r).at(c) + 1;
            }
            if (c - 1 >= 0 && mat.at(r).at(c-1) == -1) {
                q.push({r, c-1});
                mat.at(r).at(c-1) = mat.at(r).at(c) + 1;
            }
        }
        return mat;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> mat {
        {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0,0,1,1}
    };

    /*
    Output: {
        {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,2,1,1,0,1},
        {2,1,1,1,1,2,1,0,1,0},
        {3,2,2,1,0,1,0,0,1,1}}
    */

    mat = sol.updateMatrix(mat);
    print2dVector<int>(mat);

    return 0;
}