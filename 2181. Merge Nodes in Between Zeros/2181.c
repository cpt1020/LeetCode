#include <stdio.h>
#include <stdlib.h>
#include "../ListNode_C.h"

/*
gcc 2181.c ../ListNode_C.c -o 2181 && ./2181
*/

struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode *ptr = head;
    int zero_count = 0;
    int cur_sum = 0;
    struct ListNode *prev = head;

    while (ptr != NULL) {
        if (ptr->val == 0) {
            zero_count += 1;
            cur_sum = 0;
        }
        else {
            cur_sum += ptr->val;
            ptr->val = cur_sum;
        }

        if (ptr->next->val == 0) {
            if (zero_count == 1) {
                head = ptr;
            }

            prev = ptr;

            if (ptr->next->next != NULL) {
                ptr = ptr->next;
            }
            else {
                ptr->next = NULL;
                break;
            }
        }
        else {
            struct ListNode *to_free = ptr;
            ptr = ptr->next;

            if (zero_count > 1) {
                prev->next = ptr;
            }

            free(to_free);
        }
    }

    return head;
}

int main(int argc, char **argv) {

    int arr1 [] = {0,3,1,0,4,5,2,0};
    // Output: [4,11]
    struct ListNode *head = build_list(arr1, 8);
    head = mergeNodes(head);
    print_list(head);

    int arr2 [] = {0,1,0,3,0,2,2,0};
    // Output: [1,3,4]
    struct ListNode *head2 = build_list(arr2, 8);
    head2 = mergeNodes(head2);
    print_list(head2);

    return 0;
}