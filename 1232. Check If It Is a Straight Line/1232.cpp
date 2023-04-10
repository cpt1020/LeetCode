#include <vector>
#include <iostream>
using namespace std;

/*
g++ 1232.cpp -std=c++17 -o 1232 && ./1232
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }

        int y_diff {coordinates.at(1).at(0) - coordinates.at(0).at(0)};
        int x_diff {coordinates.at(1).at(1) - coordinates.at(0).at(1)};

        for (int i {2}; i < coordinates.size(); ++i) {
            vector<int> currPoint {coordinates.at(i)};
            int curr_y_diff {coordinates.at(i).at(0) - coordinates.at(i-1).at(0)};
            int curr_x_diff {coordinates.at(i).at(1) - coordinates.at(i-1).at(1)};
            
            if (x_diff * curr_y_diff != y_diff * curr_x_diff) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution sol;

    // case 1
    vector<vector<int>> coordinates {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    // ans: true
    cout << boolalpha << sol.checkStraightLine(coordinates) << endl;

    // case 2
    coordinates = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    // ans: false
    cout << boolalpha << sol.checkStraightLine(coordinates) << endl;

    // case 3
    coordinates = {{1,1},{2,2},{2,0}};
    // ans: false
    cout << boolalpha << sol.checkStraightLine(coordinates) << endl;

    // case 4
    coordinates = {{0,1},{1,3},{-4,-7},{5,11}};
    // ans: true
    cout << boolalpha << sol.checkStraightLine(coordinates) << endl;

    return 0;
}