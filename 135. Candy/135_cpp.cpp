#include <iostream>
#include <vector>
using namespace std;

/*
g++ 135_cpp.cpp -std=c++17 -o 135_cpp && ./135_cpp
*/

class Solution {
public:

    int candy(vector<int>& ratings) {
        int size {static_cast<int>(ratings.size())};
        vector<int> candies (size, 1);
        for (int i {1}; i < size; ++i) {
            if (ratings.at(i) > ratings.at(i - 1)) {
                candies.at(i) = candies.at(i - 1) + 1;
            }
        }

        for (int i {size - 2}; i >= 0; --i) {
            if (ratings.at(i) > ratings.at(i + 1)) {
                candies.at(i) = max(candies.at(i + 1) + 1, candies.at(i));
            }
        }

        int ans {0};
        for (auto it {candies.begin()}; it != candies.end(); ++it) {
            ans += *(it);
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> ratings {1,0,2};
    cout << sol.candy(ratings) << endl;

    ratings = {1,2,2};
    cout << sol.candy(ratings) << endl;

    ratings = {1,2,87,87,87,2,1};
    cout << sol.candy(ratings) << endl;

    return 0;
}