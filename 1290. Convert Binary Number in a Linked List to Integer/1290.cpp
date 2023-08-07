#include <iostream>
#include <vector>
#include "../ListNode.h"
using namespace std;

/*
g++ 1290.cpp ../ListNode.cpp -std=c++17 -o 1290 && ./1290
*/

class Solution {
public:

    int getDecimalValue(ListNode* head) {
        uint32_t bin {0};

        while (head != nullptr) {
            bin <<= 1;
            bin += head->val;
            head = head->next;
        }
        
        return bin;
    }
};

int main() {

    Solution sol;

    cout << sol.getDecimalValue(buildLinkedList({1,0,1})) << endl;

    cout << sol.getDecimalValue(buildLinkedList({1,1,1,1,1})) << endl;

    return 0;
}