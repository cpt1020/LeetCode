#include <stdio.h>
#include "../ListNode_C.h"

/*
gcc 86.c ../ListNode_C.c -o 86_C && ./86_C
*/

struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL) {
        return head;
    }

    struct ListNode *less_head = NULL, *greater_head = NULL, *less_prev = NULL, *greater_prev = NULL;

    while (head != NULL) {
        if (head->val < x) {
            if (less_prev != NULL) {
                less_prev->next = head;
                less_prev = less_prev->next;
            }
            else {
                less_head = head;
                less_prev = head;
            }
        }
        else {
            if (greater_prev != NULL) {
                greater_prev->next = head;
                greater_prev = greater_prev->next;
            }
            else {
                greater_head = head;
                greater_prev = head;
            }
        }

        head = head->next;
    }

    if (greater_prev != NULL) {
        greater_prev->next = NULL;
    }
    
    if (less_head != NULL) {
        less_prev->next = greater_head;
        return less_head;
    }
    else {
        return greater_head;
    }
}

int main(int argc, char *argv[]) {

    int arr [] = {1,4,3,2,5,2};
    int x = 3;
    // Output: [1,2,2,4,3,5]
    struct ListNode *head = build_list(arr, sizeof(arr)/sizeof(int));
    print_list(partition(head, x));

    return 0;
}