#ifndef _LISTNODE_C_H_
#define _LISTNODE_C_H_

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* node_constructor(int value, struct ListNode *next);

struct ListNode* build_list(int *arr, int size); 

void print_list(struct ListNode *head);

#endif