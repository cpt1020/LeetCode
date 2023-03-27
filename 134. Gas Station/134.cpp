#include <vector>
#include <iostream>
using namespace std;

/*
g++ 134.cpp -Wall -O2 -std=c++17 -o 134

https://leetcode.com/problems/gas-station/solutions/1706142/java-c-python-an-explanation-that-ever-exists-till-now/
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total {0};
    for (int i {0}; i < gas.size(); ++i){
        total = total + gas.at(i) - cost.at(i);
    }
    if (total < 0){
        return -1;
    }

    int size {static_cast<int>(cost.size())};
    int start {0};
    int currFuel {0};
    for (int i {0}; i < size; ++i){
        int j {i};
        currFuel = currFuel + gas.at(j % size) - cost.at(j % size);
        if (currFuel < 0){
            start = i+1;
            currFuel = 0;
        }
    }
    return (start % size);
}

int main(){

    vector<int> gas {1,2,3,4,5};
    vector<int> cost {3,4,5,1,2};
    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}