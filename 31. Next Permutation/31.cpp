#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 31.cpp ../utils.cpp -std=c++17 -o 31

https://leetcode.com/problems/next-permutation/solutions/13994/readable-code-without-confusing-i-j-and-with-explanation/
*/

void swap(vector<int>& nums, int i, int j){
    int tmp {nums.at(i)};
    nums.at(i) = nums.at(j);
    nums.at(j) = tmp;
}

void reverseSuffix(vector<int>& nums, int start) {
    int end = static_cast<int>(nums.size() - 1);
    while (start < end) {
        swap(nums, start++, end--);
    }
}

void nextPermutation(vector<int>& nums) {
    int size {static_cast<int>(nums.size())};
    if (size == 1){
        return;
    }

    int pivot {size - 1};
    while (pivot > 0){
        if (nums.at(pivot-1) < nums.at(pivot)){
            break;
        }
        --pivot;
    }

    if (pivot == 0){
        reverse(nums.begin(), nums.end());
        return;
    }
    else {
        int val {nums.at(pivot - 1)};
        int i {size - 1};
        while (i >= pivot){
            if (nums.at(i) > val){
                break;
            }
            --i;
        }
        swap(nums, i, pivot - 1);
        reverseSuffix(nums, pivot);
        return;
    }
}


int main(){
    
    vector<int> nums {1,2,0,3,0,1,2,4};
    nextPermutation(nums);
    printVector(nums);

    return 0;
}