#include <iostream>
#include "../ListNode.h"
using namespace std;

/*
g++ 328.cpp ../ListNode.cpp -std=c++17 -o 328 && ./328
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        int count {1};
        ListNode* oddHead {nullptr};
        ListNode* oddPtr {oddHead};
        ListNode* evenHead {nullptr};
        ListNode* evenPtr {evenHead};
        ListNode* ptr {head};

        while (ptr != nullptr) {
            if (count == 1) {
                oddHead = head;
                oddPtr = oddHead;
                ptr = ptr->next;
            }
            else if (count == 2) {
                evenHead = ptr;
                evenPtr = evenHead;
                oddPtr->next = ptr->next;
                ptr = ptr->next;
                evenPtr->next = nullptr;
            }
            else if (count % 2 == 1) {
                oddPtr = ptr;
                ptr = ptr->next;
            }
            else {
                evenPtr->next = ptr;
                oddPtr->next = ptr->next;
                ptr = ptr->next;
                evenPtr = evenPtr->next;
                evenPtr->next = nullptr;
            }
            count += 1;
        }

        oddPtr->next = evenHead;
        return oddHead;
    }
};

/*
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return head;
    }

    int node_size {0};
    ListNode* ptr {head};
    while (ptr != nullptr){
        node_size += 1;
        ptr = ptr->next;
    }

    int node_count {1};
    ListNode* last_odd {head};
    ListNode* last_even {head->next};

    while (node_count <= (node_size-2)){
        if (node_count % 2 == 1){
            ListNode* tmp = last_even->next;
            last_even->next = tmp->next;
            tmp->next = last_odd->next;
            last_odd->next = tmp;
            last_odd = last_odd->next;
        }
        else{
            last_even = last_even->next;
        }

        node_count += 1;
    }
    return head;
}
*/

int main(){

    Solution sol;

    // case 1
    ListNode* ptr {buildLinkedList({1,2,3,4,5})};
    // ans: [1,3,5,2,4]
    printList(sol.oddEvenList(ptr));

    // case 2
    ptr = {buildLinkedList({2,1,3,5,6,4,7})};
    // ans: [2,3,6,7,1,5,4]
    printList(sol.oddEvenList(ptr));

    return 0;
}