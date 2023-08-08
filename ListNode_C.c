#include <stdio.h>
#include <stdlib.h>
#include "ListNode_C.h"

struct ListNode* node_constructor(int value, struct ListNode *next) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = next;

    return node;
}

struct ListNode* build_list(int *arr, int size) {

    struct ListNode *head = node_constructor(arr[0], NULL);
    struct ListNode *prev = head;

    for (int i = 1; i < size; ++i) {
        struct ListNode *node = node_constructor(arr[i], NULL);

        prev->next = node;
        prev = node;
    }

    return head;
}

void print_list(struct ListNode *head) {

    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}