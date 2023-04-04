#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
g++ 152.cpp -std=c++17 -o 152 && ./152
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans {INT_MIN};
        int minProd {1}, maxProd {1};

        for (auto num: nums) {
            if (num < 0) {
                swap(minProd, maxProd);
            }

            maxProd = max(maxProd * num, num);
            minProd = min(minProd * num, num);
            ans = max(ans, maxProd);
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums {2,3,-2,4};
    cout << sol.maxProduct(nums) << endl;

    return 0;
}