#include <vector>
#include <iostream>
using namespace std;

/*
g++ 2660.cpp -std=c++17 -o 2660 && ./2660
*/

class Solution {
private:
    int score(vector<int>& player) {
        int sum {0};
        int foundTen {0};
        
        for (auto& pin: player) {
            if (foundTen > 0) {
                sum += pin*2;
            }
            else {
                sum += pin;
            }
            
            foundTen -= 1;
            
            if (pin == 10) {
                foundTen = 2;
            }
        }
        
        return sum;
    }

public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 {score(player1)};
        int score2 {score(player2)};
        
        if (score1 > score2) {
            return 1;
        }
        else if (score1 < score2) {
            return 2;
        }
        else {
            return 0;
        }
    }
};

int main() {

    Solution sol;

    vector<int> player1 {4,10,7,9};
    vector<int> player2 {6,5,2,3};
    // Output: 1
    cout << sol.isWinner(player1, player2) << endl;

    player1 = {3,5,7,6};
    player2 = {8,10,10,2};
    // Output: 2
    cout << sol.isWinner(player1, player2) << endl;

    player1 = {2,3};
    player2 = {4,1};
    // Output: 0
    cout << sol.isWinner(player1, player2) << endl;

    return 0;
}