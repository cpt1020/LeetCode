#include <stdio.h>
#include "../ListNode_C.h"

/*
gcc 2130.c ../ListNode_C.c -o 2130 && ./2130
*/

int pairSum(struct ListNode* head){

    if (head->next->next == NULL) {
        return head->val + head->next->val;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *next_node = NULL;

    while (slow != NULL) {
        next_node = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next_node;
    }

    int max_sum = 0;
    while (prev != NULL) {
        max_sum = (max_sum < (head->val + prev->val)) ? (head->val + prev->val) : max_sum;
        prev = prev->next;
        head = head->next;
    }

    return max_sum;
}

int main(int argc, char *argv[]) {

    int arr [] = {5,4,2,1};
    struct ListNode *head = build_list(arr, sizeof(arr)/sizeof(int));
    // Output: 6
    printf("%d\n", pairSum(head));

    int arr2 [] = {4,2,2,3};
    struct ListNode *head2 = build_list(arr2, sizeof(arr2)/sizeof(int));
    // Output: 7
    printf("%d\n", pairSum(head2));

    return 0;
}