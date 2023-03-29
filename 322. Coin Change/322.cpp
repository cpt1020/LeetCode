#include <iostream>
#include <vector>
using namespace std;

/*
g++ 322.cpp -std=c++17 -o 322
*/

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());

    vector<int> money (amount + 1, amount + 1);
    money.at(0) = 0;
    for (int i {1}; i <= amount; ++i){
        for (auto coin: coins){
            if (i >= coin){
                money.at(i) = min(money.at(i-coin)+1, money.at(i));
            }
        }
    }

    if (money.at(amount) > amount){
        return -1;
    }
    else {
        return money.at(amount);
    }
}

int main(){

    vector<int> coins {1,2,5};
    int amount {11};
    cout << coinChange(coins, amount) << endl;

    return 0;
}