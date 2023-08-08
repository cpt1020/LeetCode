#include <stdio.h>
#include "../ListNode_C.h"

/*
gcc 1721.c ../ListNode_C.c -o 1721 && ./1721
*/

struct ListNode* swapNodes(struct ListNode* head, int k){
    int size = 0;
    struct ListNode *ptr = head;
    struct ListNode *node1 = head, *node2 = head;

    while (ptr != NULL) {

        size += 1;

        if (size == k) {
            node1 = ptr;
        }
        else if (size > k) {
            node2 = node2->next;
        }

        ptr = ptr->next;
    }

    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;

    return head;
}

int main(int argc, char **argv) {

    int arr1 [] = {1,2,3,4,5};
    int k = 2;
    struct ListNode *head1 = build_list(arr1, 5);
    // Output: [1,4,3,2,5]
    print_list(swapNodes(head1, k));

    int arr2 [] = {7,9,6,6,7,8,3,0,9,5};
    k = 5;
    struct ListNode *head2 = build_list(arr2, 10);
    // Output: [7,9,6,6,8,7,3,0,9,5]
    print_list(swapNodes(head2, k));

    return 0;
}