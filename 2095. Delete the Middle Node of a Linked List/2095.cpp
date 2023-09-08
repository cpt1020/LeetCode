#include <iostream>
#include "../ListNode.h"
using namespace std;

/*
g++ 2095.cpp ../ListNode.cpp -std=c++17 -Wall -o 2095_cpp && ./2095_cpp
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }

        ListNode *fast {head}, *slow {head}, *prev {nullptr};
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        delete slow;
        return head;
    }
};

int main() {

    Solution sol;

    ListNode *head1 {buildLinkedList({1,3,4,7,1,2,6})};
    head1 = sol.deleteMiddle(head1);
    printList(head1);

    ListNode *head2 {buildLinkedList({1,2,3,4})};
    head2 = sol.deleteMiddle(head2);
    printList(head2);

    return 0;
}