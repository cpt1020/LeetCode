#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

/*
g++ 2614.cpp -std=c++17 -o 2614 && ./2614
*/

class Solution {

    bool isPrime(int num) {
        if (num == 1) {
            return false;
        }
        else if (num == 2) {
            return true;
        }
        else if (num % 2 == 0) {
            return false;
        }
        
        for (int i {2}; i < sqrt(num)+1; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    
    int diagonalPrime(vector<vector<int>>& nums) {
        
        vector<int> num;
        int len {static_cast<int>(nums.size())};
        
        for (int i {0}; i < len; ++i){
            
            if (isPrime(nums.at(i).at(i)) == true) {
                num.push_back(nums.at(i).at(i));
            }
            
            if (isPrime(nums.at(len-i-1).at(i)) == true) {
                num.push_back(nums.at(len-i-1).at(i));
            }
        }
        
        if (num.size() == 0) {
            return 0;
        }
        else {
            sort(num.begin(), num.end(), [](const int& a, const int& b){return a > b;});
            return num.at(0);
        }
    }
};

int main() {

    Solution sol;

    // case 1
    vector<vector<int>> nums {{1,2,3},{5,6,7},{9,10,11}};
    // ans: 11
    cout << sol.diagonalPrime(nums) << endl;

    // case 2
    nums = {{1,2,3},{5,17,7},{9,11,10}};
    // ans: 17
    cout << sol.diagonalPrime(nums) << endl;

    return 0;
}