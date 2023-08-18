#include <iostream>
#include "../ListNode.h"
using namespace std;

/*
g++ 143.cpp ../ListNode.cpp -std=c++17 -o 143 && ./143
*/

class Solution {
public:

    void reorderList(ListNode* head) {

        if (head->next == nullptr) {
            return;
        }

        // find middle node
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev_of_slow {dummy};
        ListNode *fast {head}, *slow {head};
        while (fast != nullptr && fast->next != nullptr) {
            prev_of_slow = prev_of_slow->next;
            slow = slow->next;
            fast = fast->next->next;
        }

        // set the next ptr of the node b4 middle node to nullptr
        prev_of_slow->next = nullptr;
        delete dummy;

        // reverse 2nd part of the list
        ListNode *prev {nullptr};
        ListNode *next {nullptr};
        while (slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // merge 1st and 2nd lists together
        ListNode *next2 {nullptr};
        while (prev != nullptr && head != nullptr) {
            next = head->next;
            next2 = prev->next;
            head->next = prev;
            prev->next = next;

            if (next == nullptr && next2 == nullptr) { // even number case
                return;
            }
            else if (next2 != nullptr && next == nullptr) { // odd number case
                prev->next = next2;
                return;
            }

            head = next;
            prev = next2;
        }
    }
};

int main() {

    Solution sol;

    ListNode *head {buildLinkedList({1,2,3,4,5})};
    // Output: [1,5,2,4,3]
    sol.reorderList(head);
    printList(head);

    return 0;
}