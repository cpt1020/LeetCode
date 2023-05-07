#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 2672.cpp ../utils.cpp -std=c++17 -o 2672 && ./2672
*/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums (n, 0);
        vector<int> ans (queries.size(), 0);
        
        int adj {0};
        for (int i {0}; i < queries.size(); ++i) {
            int pos {queries.at(i).at(0)};
            int color {queries.at(i).at(1)};
            
            if (nums.at(pos) == 0) {
                nums.at(pos) = color;
                
                if (pos - 1 >= 0 && nums.at(pos-1) == color) {
                    adj += 1;
                }
                if (pos + 1 < n && nums.at(pos+1) == color) {
                    adj += 1;
                }
            }
            else {
                if (pos - 1 >= 0 && nums.at(pos) == nums.at(pos-1) && nums.at(pos-1) != color) {
                    adj -= 1;
                }
                if (pos + 1 < n && nums.at(pos) == nums.at(pos+1) && nums.at(pos+1) != color) {
                    adj -= 1;
                }
                
                int oriColor = nums.at(pos);
                nums.at(pos) = color;
                
                if (pos - 1 >= 0 && nums.at(pos-1) == color && color != oriColor) {
                    adj += 1;
                }
                if (pos + 1 < n && nums.at(pos+1) == color && color != oriColor) {
                    adj += 1;
                }
            }
            
            ans.at(i) = adj;
        }
        
        return ans;
    }
};

int main() {

    Solution sol;

    int n {4};
    vector<vector<int>> queries {{0,2},{1,2},{3,1},{1,1},{2,1}};
    // Output: [0,1,1,0,2]
    printVector<int>(sol.colorTheArray(n, queries));

    n = 1;
    queries = {{0,100000}};
    // Output: [0]
    printVector<int>(sol.colorTheArray(n, queries));

    return 0;
}