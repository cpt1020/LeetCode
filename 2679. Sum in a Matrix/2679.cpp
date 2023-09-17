#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int matrixSum(vector<vector<int>>& nums) {
        int row = nums.size();
        int col = nums.at(0).size();
        int ans {0};

        for (int i {0}; i < nums.size(); ++i) {
            sort(nums.at(i).begin(), nums.at(i).end());
        }

        for (int i = nums.at(0).size() - 1; i >= 0; --i) {
            int max_num {0};
            for (int j {0}; j < nums.size(); ++j) {
                max_num = max(nums.at(j).at(i), max_num);
            }
            ans += max_num;
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> nums {{7,2,1},{6,4,2},{6,5,3},{3,2,1}};
    // Output: 15
    cout << sol.matrixSum(nums) << endl;

    nums = {{1}};
    // Output: 1
    cout << sol.matrixSum(nums) << endl;

    return 0;
}