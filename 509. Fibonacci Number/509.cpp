#include <iostream>
#include <vector>
using namespace std;

/*
g++ 509.cpp -std=c++17 -o 509
*/

int fib(int n) {
    if (n == 0 || n == 1){
        return n;
    }

    vector<int> fibNums (n + 1, 0);
    fibNums.at(1) = 1;
    for (int i {2}; i <= n; ++i){
        fibNums.at(i) = fibNums.at(i-1) + fibNums.at(i-2);
    }

    return fibNums.at(n);
}

int main(){

    cout << fib(10) << endl;

    return 0;
}