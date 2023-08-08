#include <vector>
#include <iostream>
using namespace std;

/*
g++ 33.cpp -std=c++17 -o 33 && ./33
*/

int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left {0}, right {size - 1};
    int middle {0};

    while (left < right) {
        middle = (left + right)/2;

        if (nums.at(middle) > nums.at(right)) {
            left = middle + 1;
        }
        else { // nums.at(middle) < nums.at(right)
            right = middle;
        }
    }

    int rotate {left};
    right = left + size - 1;
    middle = 0;

    while (left <= right) {
        middle = (left + right)/2;

        if (nums.at(middle % size) == target) {
            return middle % size;
        }

        if (target < nums.at(middle % size)) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    return -1;
}

int main(){
    
    vector<int> nums {4,5,6,7,0,1,2};
    int target {0};
    cout << search(nums, target) << endl;

    return 0;
}