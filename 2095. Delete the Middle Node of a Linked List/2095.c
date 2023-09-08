#include <stdio.h>
#include <stdlib.h>
#include "../ListNode_C.h"

/*
gcc 2095.c ../ListNode_C.c -Wall -o 2095_c && ./2095_c
*/

struct ListNode* deleteMiddle(struct ListNode* head){
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }

    struct ListNode *fast = head, *slow = head;
    struct ListNode *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);
    return head;
}

int main(int argc, char *argv[]) {

    int nums1 [] = {1,3,4,7,1,2,6};
    struct ListNode *head = build_list(nums1, sizeof(nums1)/sizeof(int));
    head = deleteMiddle(head);
    print_list(head);

    int nums2 [] = {1,2,3,4};
    struct ListNode *head2 = build_list(nums2, sizeof(nums2)/sizeof(int));
    head2 = deleteMiddle(head2);
    print_list(head2);

    return 0;
}