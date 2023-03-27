#include <iostream>
#include <vector>
using namespace std;

/*
g++ 198.cpp -Wall -O2 -std=c++17 -o 198
*/

int rob(vector<int>& nums){
    int prev1 {0};
    int prev2 {0};
    for (auto & num: nums){
        int tmp {prev1};
        prev1 = max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}

int main(){

    vector<int> nums1 {2,7,9,3,1};
    cout << rob(nums1) << endl;

    return 0;
}