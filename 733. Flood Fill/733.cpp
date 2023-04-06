#include <iostream>
#include <vector>
#include <queue> // for bfs
#include "../utils.h"
using namespace std;

/*
g++ 733.cpp ../utils.cpp -std=c++17 -o 733 && ./733
*/

class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j, const int& oriColor , const int& color, const int& row, const int& col) {
        image.at(i).at(j) = color;
        
        if (i + 1 < row && image.at(i+1).at(j) == oriColor) {
            dfs(image, i+1, j, oriColor, color, row, col);
        }
        if (i - 1 >= 0 && image.at(i-1).at(j) == oriColor) {
            dfs(image, i-1, j, oriColor, color, row, col);
        }
        if (j + 1 < col && image.at(i).at(j + 1) == oriColor) {
            dfs(image, i, j+1, oriColor, color, row, col);
        }
        if (j - 1 >= 0 && image.at(i).at(j - 1) == oriColor) {
            dfs(image, i, j-1, oriColor, color, row, col);
        }
    }

    void bfs(vector<vector<int>>& image, int sr, int sc,const int& oriColor, const int& color, const int& row, const int& col) {
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (q.empty() != true) {
            int r {q.front().first};
            int c {q.front().second};
            q.pop();
            image.at(r).at(c) = color;

            if (r+1 < row && image.at(r+1).at(c) == oriColor) {
                q.push({r+1, c});
            }
            if (r-1 >= 0 && image.at(r-1).at(c) == oriColor) {
                q.push({r-1, c});
            }
            if (c+1 < col && image.at(r).at(c+1) == oriColor) {
                q.push({r, c+1});
            }
            if (c-1 >= 0 && image.at(r).at(c-1) == oriColor) {
                q.push({r, c-1});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        size_t row {image.size()};
        size_t col {image.at(0).size()};
        int oriColor {image.at(sr).at(sc)};
        if (oriColor != color) {
            dfs(image, sr, sc, oriColor, color, row, col);
            // bfs(image, sr, sc, oriColor, color, row, col);
        }
        return image;
    }
};

int main(){

    Solution sol;

    vector<vector<int>> image {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr {1}, sc {1}, color {2};

    print2dVector(sol.floodFill(image, sr, sc, color));

    return 0;
}