#include <iostream>
#include <vector>
using namespace std;

/*
g++ 1863.cpp -std=c++17 -o 1863 && ./1863
*/

class Solution {
public:

    int subsetXORSum(vector<int>& nums) {

        vector<vector<int>> subset {{}};

        for (int i {0}; i < nums.size(); ++i) {
            int size = subset.size();

            for (int j {0}; j < size; ++j) {
                vector<int> tmp {subset.at(j)};
                tmp.push_back(nums.at(i));
                subset.push_back(tmp);
            }
        }

        int ans {0};
        for (auto& vec : subset) {
            if (vec.size() != 0) {
                int sum {vec.at(0)};
                for (int i {1}; i < vec.size(); ++i) {
                    sum ^= vec.at(i);
                }
                ans += sum;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums {5,1,6};
    // Output: 28
    cout << sol.subsetXORSum(nums) << endl;

    return 0;
}