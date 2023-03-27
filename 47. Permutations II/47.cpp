#include <vector>
#include <iostream>
#include <algorithm>
#include "../utils.h"
using namespace std;

/*
g++ 47.cpp ../utils.cpp -std=c++17 -o 47
*/

void swap(vector<int>& nums, int i, int j){
    int tmp {nums.at(i)};
    nums.at(i) = nums.at(j);
    nums.at(j) = tmp;
}

void perm(vector<vector<int>>& ans, vector<int>& nums, int i, int size){
    if (i == size){
        if (find(ans.begin(), ans.end(), nums) == ans.end()){
            ans.push_back(nums);
        }
    }
    else {
        for (int j {i}; j <= size; ++j){
            swap(nums, i, j);
            perm(ans, nums, i+1, size);
            swap(nums, i, j);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int size {static_cast<int>(nums.size())};
    perm(ans, nums, 0, size - 1);
    return ans;
}

int main(){

    vector<int> nums {1,1,3};
    print2dVector(permute(nums));

    return 0;
}