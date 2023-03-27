#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 739.cpp ../utils.cpp -Wall -O2 -std=c++17 -o 739

https://leetcode.com/problems/daily-temperatures/solutions/1574806/c-easy-standard-sol-intuitive-approach-with-dry-run-stack-appraoch/
*/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int tempSize {static_cast<int>(temperatures.size())};
    if (tempSize == 1){
        vector<int> answer {0};
        return answer;
    }

    stack<int> temps;
    stack<int> index;
    vector<int> answer {0};

    temps.push(temperatures.at(tempSize-1));
    index.push(tempSize-1);

    for (int i {tempSize-2}; i >= 0; --i){
        while (temps.empty() != true && temps.top() <= temperatures.at(i)){
            temps.pop();
            index.pop();
        }

        if (temps.empty() == true){
            answer.push_back(0);
        }
        else{
            answer.push_back(index.top() - i);
        }

        temps.push(temperatures.at(i));
        index.push(i);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){

    vector<int> temps1 {73,74,75,71,69,72,76,73};
    vector<int> ans {dailyTemperatures(temps1)};
    printVector(ans);

    return 0;
}