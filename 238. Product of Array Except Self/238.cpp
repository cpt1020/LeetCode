#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 238.cpp ../utils.cpp -std=c++17 -o 238 && ./238
*/

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans (nums.size(), 1);
    vector<int> prefix (nums.size(), 1);
    vector<int> suffix (nums.size(), 1);

    prefix.at(0) = nums.at(0);
    suffix.at(nums.size()-1) = nums.at(nums.size()-1);
    
    for(int i {1}; i < nums.size(); i++){
        prefix.at(i) = prefix.at(i-1) * nums.at(i);
    }

    for (int i {static_cast<int>(nums.size()-2)}; i >= 0; --i){
        suffix.at(i) = suffix.at(i+1) * nums.at(i);
    }

    ans.at(0) = suffix.at(1);
    ans.at(nums.size()-1) = prefix.at(nums.size()-2);

    for (int i {1}; i < nums.size()-1; ++i){
        ans.at(i) = prefix.at(i-1)*suffix.at(i+1);
    }

    return ans;
}

int main(){

    vector<int> nums {1,2,3,4};
    printVector(productExceptSelf(nums));

    return 0;
}