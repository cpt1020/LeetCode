#include <vector>
#include <iostream>
using namespace std;

/*
g++ -Wall 11.cpp -std=c++17 -o 11 && ./11
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left {0};
        int right {static_cast<int>(height.size()-1)};
        int water {0};

        while (left < right) {
            water = max(water, (right - left) * min(height.at(left), height.at(right)));

            if (height.at(left) < height.at(right)) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }

        return water;
    }
};

int main() {

    Solution sol;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;

    return 0;
}