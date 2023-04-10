#include <iostream>
#include "ListNode.h"
#include <vector>
using namespace std;

ListNode::ListNode() {
    val = 0;
    next = nullptr;
}

ListNode::ListNode(int x) {
    val = x;
    next = nullptr;
}

ListNode::ListNode(int x, ListNode *next_node) {
    val = x;
    next = next_node;
}

void printList(ListNode* head) {

    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* buildLinkedList(vector<int> vec) {

    ListNode* prev {nullptr};
    for (int i = vec.size()-1; i >= 0; --i) {
        if (i == vec.size() - 1) {
            ListNode* node = new ListNode(vec.at(i));
            prev = node;
        }
        else {
            ListNode* node = new ListNode(vec.at(i), prev);
            prev = node;
        }
    }
    return prev;
}