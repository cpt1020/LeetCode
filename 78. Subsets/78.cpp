#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 78.cpp ../utils.cpp -std=c++17 -o 78 && ./78

https://leetcode.com/problems/subsets/solutions/27278/c-recursive-iterative-bit-manipulation/
*/

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> empty {};
    ans.push_back(empty);

    for (auto num: nums){
        int size {static_cast<int>(ans.size())};
        // this step is important!
        
        for (int i {0}; i < size; ++i){
            vector<int> tmp {ans.at(i)};
            tmp.push_back(num);
            ans.push_back(tmp);
        }
    }
    
    return ans;
}

int main(){

    vector<int> nums {1,2,3};
    print2dVector(subsets(nums));

    return 0;
}