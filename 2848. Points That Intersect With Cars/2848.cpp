#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
g++ 2848.cpp -std=c++17 -o 2848 && ./2848
*/

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int> &vec1, vector<int> &vec2) {
            if (vec1.at(0) != vec2.at(0)) {
                return vec1.at(0) < vec2.at(0);
            }
            else {
                return vec1.at(1) < vec2.at(1);
            }
        });
        
        vector<pair<int,int>> tmp {{nums.at(0).at(0), nums.at(0).at(1)}};
        int idx {0};
        for (int i {1}; i < nums.size(); ++i) {
            if (nums.at(i).at(0) > tmp.at(idx).second) {
                tmp.push_back({nums.at(i).at(0), nums.at(i).at(1)});
                idx++;
            }
            else if (nums.at(i).at(1) > tmp.at(idx).second) {
                tmp.at(idx).second = nums.at(i).at(1);
            }
        }
        
        int res {0};
        for (const auto &p : tmp) {
            res += (p.second - p.first + 1);
        }
        
        return res;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> nums {{3,6},{1,5},{4,7}};
    cout << sol.numberOfPoints(nums) << endl;

    nums = {{1,3},{5,8}};
    cout << sol.numberOfPoints(nums) << endl;

    return 0;
}