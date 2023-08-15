#include <iostream>
#include "../ListNode.h"

/*
g++ 86.cpp ../ListNode.cpp -std=c++17 -o 86 && ./86
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }

        ListNode *less_head {nullptr}, *greater_head {nullptr}, *less_prev {nullptr}, *greater_prev {nullptr};

        while (head != nullptr) {
            if (head->val < x) {
                if (less_prev != nullptr) {
                    less_prev->next = head;
                    less_prev = less_prev->next;
                }
                else {
                    less_head = head;
                    less_prev = head;
                }
            }
            else {
                if (greater_prev != nullptr) {
                    greater_prev->next = head;
                    greater_prev = greater_prev->next;
                }
                else {
                    greater_head = head;
                    greater_prev = head;
                }
            }

            head = head->next;
        }

        if (greater_prev != nullptr) {
            greater_prev->next = nullptr;
        }
        
        if (less_head != nullptr) {
            less_prev->next = greater_head;
            return less_head;
        }
        else {
            return greater_head;
        }
    }
};

int main() {

    Solution sol;

    ListNode *head {buildLinkedList({1,4,3,2,5,2})};
    int x {3};
    // Output: [1,2,2,4,3,5]
    printList(sol.partition(head, x));

    return 0;
}