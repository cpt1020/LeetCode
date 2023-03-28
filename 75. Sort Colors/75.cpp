#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 75.cpp ../utils.cpp -std=c++17 -o 75 && ./75
*/

int findMin(vector<int>& nums, int start, int end){
    int min {start};
    for (int i {start + 1}; i < end; ++i){
        if (nums.at(i) < nums.at(min)){
            min = i;
        }
    }
    return min;
}

void swap(vector<int>& nums, int i, int j){
    int tmp {nums.at(i)};
    nums.at(i) = nums.at(j);
    nums.at(j) = tmp;
}

void sortColors(vector<int>& nums) {
    // insertion sort

    int size {static_cast<int>(nums.size())};

    for (int i {0}; i < size - 1; ++i){
        int min {findMin(nums, i, size)};
        if (min != i){
            swap(nums, i, min);
        }
    }
}

int main(){

    vector<int> nums {2,0,1};
    sortColors(nums);
    printVector(nums);
    
    return 0;
}