#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x {abs(fx - sx)};
        int y {abs(fy - sy)};

        if (x == 0 && y == 0 && t == 1) {
            return false;
        }

        int time {min(x, y) + abs(x - y)};
        return time <= t;
    }
};

int main() {

    Solution sol;

    cout << boolalpha << sol.isReachableAtTime(2,4,7,7,6) << endl;
    cout << sol.isReachableAtTime(3,1,7,3,3) << endl;

    return 0;
}