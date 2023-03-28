#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {

    int size {static_cast<int>(nums.size())};
    int left {0};
    int right {size - 1};
    int middle {left + (right - left) / 2};
    
    while (left <= right){

        if (nums.at(middle) == target){
            return middle;
        }

        if (nums.at(middle) >= nums.at(left)){
            if (target >= nums.at(left) && target <= nums.at(middle)){
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        else{ // nums.at(middle) < nums.at(left)
            if (target <= nums.at(right) && target >= nums.at(middle)){
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        middle = left + (right - left) / 2;
    }
    return -1;
}

int main(){
    
    vector<int> nums {4,5,6,7,0,1,2};
    int target {0};
    cout << search(nums, target) << endl;

    return 0;
}