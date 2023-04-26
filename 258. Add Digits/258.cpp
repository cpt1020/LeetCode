#include <iostream>
using namespace std;

/*
g++ 258.cpp -std=c++17 -o 258 && ./258
*/

class Solution {
public:
    int addDigits(int num) {

        while (true) {
            int sum {0};
            while (num >= 1) {
                sum += (num % 10);
                num /= 10;
            }

            num = sum;
            if (num / 10 < 1) {
                break;
            }
        }
        
        return num;
    }

    int addDigits_optimized(int num) {

        if (num == 0) {
            return 0;
        }
        else if (num % 9 == 0) {
            return 9;
        }
        else {
            return (num % 9);
        }
    }
};

int main() {

    Solution sol;

    cout << sol.addDigits(38) << endl;
    cout << sol.addDigits_optimized(38) << endl;

    return 0;
}