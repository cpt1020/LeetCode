#include <iostream>
#include <vector>
using namespace std;

/*
g++ 62.cpp -std=c++17 -o 62 && ./62
*/

int uniquePaths(int m, int n) {
    vector<vector<int>> dpTable (m, vector<int>(n, 1));
    for (int i {1}; i < m; ++i){
        for (int j {1}; j < n; ++j){
            dpTable.at(i).at(j) = dpTable.at(i).at(j-1) + dpTable.at(i-1).at(j);
        }
    }
    return dpTable.at(m-1).at(n-1);
}

int main(){

    cout << uniquePaths(3, 7) << endl;

    return 0;
}