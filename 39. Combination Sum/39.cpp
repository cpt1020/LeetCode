#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

class Solution {
public:

    void comb(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> currCombination, int index, int currSum) {
        if (currSum > target) {
            return;
        }
        if (currSum == target) {
            ans.push_back(currCombination);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            currCombination.push_back(candidates[i]);
            currSum += candidates[i];
            comb(candidates, target, ans, currCombination, i, currSum);
            // if "comb(candidates, target, ans, currCombination, index, currSum);"
            // we get all the possible of combination
            currCombination.pop_back();
            currSum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currCombination;
        comb(candidates, target, ans, currCombination, 0, 0);
        return ans;
    }

};

int main() {

    Solution sol;
    
    vector<int> candidates {2,3,6,7};
    int target {7};
    print2dVector(sol.combinationSum(candidates, target));

    return 0;
}