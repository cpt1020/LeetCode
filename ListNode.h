#ifndef LISTNODE_H
#define LISTNODE_H
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next_node);
};

void printList(ListNode* head);

ListNode* buildLinkedList(vector<int> vec);

#endif