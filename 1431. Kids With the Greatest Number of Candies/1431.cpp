#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 1431.cpp ../utils.cpp -std=c++17 -o 1431 && ./1431
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies {*max_element(candies.begin(), candies.end())};
        vector<bool> res;
        for (auto can: candies) {
            if (can+extraCandies >= maxCandies) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};

int main() {

    Solution sol;

    vector<int> candies {2,3,5,1,3};
    printVector(sol.kidsWithCandies(candies, 3));

    candies = {4,2,1,1,2};
    printVector(sol.kidsWithCandies(candies, 1));

    return 0;
}