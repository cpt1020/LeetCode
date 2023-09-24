#include <iostream>
#include <vector>
using namespace std;

/*
g++ 799.cpp -std=c++17 -o 799cpp && ./799cpp
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {static_cast<double>(poured)};

        for (int r {0}; r <= query_row; ++r) {
            vector<double> next_row (r + 2, 0);
            for (int j {0}; j <= r; ++j) {
                if (row.at(j) > 1) {
                    row.at(j) -= 1;
                    next_row.at(j) += row.at(j)/2.0;
                    next_row.at(j+1) += row.at(j)/2.0;
                    row.at(j) = 1;
                }
            }

            if (r != query_row) {
                row = next_row;
            }
        }

        return row.at(query_glass);
    }
};

int main() {

    Solution sol;

    int poured = 1, query_row = 1, query_glass = 1;
    // Output: 0.00000
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    poured = 2, query_row = 1, query_glass = 1;
    // Output: 0.50000
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    poured = 100000009, query_row = 33, query_glass = 17;
    // Output: 1.00000
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    return 0;
}