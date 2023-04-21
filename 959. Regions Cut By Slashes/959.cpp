#include <vector>
#include <iostream>
using namespace std;

/*
g++ 959.cpp -std=c++17 -o 959 && ./959
*/

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        // split each cell into 4 triangles

        int n = grid.size();
        int count {n*n*4};  // total number of triangle at the beginning
        vector<int> parent; // store the parent of each triangle
        for (int i {0}; i < count; ++i) {
            parent.push_back(i);
            // initialize the parent of each triangle to itself
        }

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < n; ++j) {
                if (i > 0) {
                    unionSet(parent, g(i-1,j,2, n), g(i,j,0,n), count);
                    // merge triangles 2 and 0 from two squares vertically
                }
                if (j > 0) {
                    unionSet(parent, g(i,j-1,1,n),g(i,j,3,n), count);
                    // merge trianges 1 and 3 from two squares horizontally
                    // These triangles are supposed to be contiguous originally
                }

                if (grid.at(i).at(j) != '/') {
                    // if it is "\\" or empty, apply common operations
                    unionSet(parent, g(i,j,0,n),g(i,j,1,n), count);
                    unionSet(parent, g(i,j,2,n),g(i,j,3,n), count);
                }

                if (grid.at(i).at(j) != '\\') {
                    // if it is "/" or empty, apply common operations.
                    unionSet(parent, g(i,j,0,n), g(i,j,3,n), count);
                    unionSet(parent, g(i,j,2,n), g(i,j,1,n), count);
                }
            }
        }

        //return number of polygons in the graph
        return count;
    }

    int findSet(vector<int>& parent, int& x) {
        if (x != parent.at(x)) {
            parent.at(x) = findSet(parent, parent.at(x));
        }
        return parent.at(x);
    }

    void unionSet(vector<int>& parent, int x, int y, int& count) {
        int parent1 {findSet(parent, x)};
        int parent2 {findSet(parent, y)};
        if (parent1 != parent2) {
            parent.at(max(parent1, parent2)) = min(parent1, parent2);
            count -= 1;
            //merge two polygons to a bigger polygon will decrease number of polygons by 1
        }
    }

    int g(int i, int j, int k, int n) {
        // find the corresponding position for current triangle
        // Think this 1D array as a 2D array and each element is an array of size 4.
        return ((i * n + j) * 4 + k);
    }
};

int main() {

    Solution sol;

    vector<string> grid {" /","/ "};
    // ans: 2
    cout << sol.regionsBySlashes(grid) << endl;

    grid = {" /","  "};
    // ans: 1
    cout << sol.regionsBySlashes(grid) << endl;

    grid = {"/\\","\\/"};
    // ans: 5
    cout << sol.regionsBySlashes(grid) << endl;

    return 0;
}