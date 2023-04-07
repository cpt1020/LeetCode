#include <vector>
#include <iostream>
using namespace std;

/*
g++ 416.cpp -std=c++17 -o 416 && ./416
*/

/*
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) {
            return false;
        }
        int sum {0};
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector<vector<int>> s {{}};
        for (auto num: nums) {
            int size {static_cast<int>(s.size())};
            for (int i {0}; i < size; ++i) {
                vector<int> tmp {s.at(i)};
                tmp.push_back(num);
                s.push_back(tmp);
            }
        }

        for (int i {1}; i < s.size() - 1; ++i) {
            int partialSum {0};
            for (auto num: s.at(i)) {
                partialSum += num;
            }
            if (partialSum == (sum - partialSum)) {
                return true;
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) {
            return false;
        }

        int sum {0};
        for (auto num: nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false;
        }

        int target {sum/2};

        vector<vector<int>> s (nums.size() + 1, vector<int> (target + 1, 0));
        for (int i {1}; i <= nums.size(); ++i) {
            for (int w {1}; w <= target; ++w) {
                if (w < nums.at(i-1)) {
                    s.at(i).at(w) = s.at(i-1).at(w);
                }
                else {
                    s.at(i).at(w) = max(s.at(i-1).at(w), nums.at(i-1) + s.at(i-1).at(w-nums.at(i-1)));
                }
            }
        }
        return s.at(nums.size()).at(target) == target;
    }
};

int main() {

    Solution sol;
    vector<int> nums {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
    cout << boolalpha << sol.canPartition(nums) << endl;
    
    return 0;
}