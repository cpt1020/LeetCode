#include <stdio.h>
#include "../ListNode_C.h"

/*
gcc 206.c ../ListNode_C.c -o 206 && ./206
*/

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return head;
    }

    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

int main(int argc, char **argv) {

    int arr [] = {1,2,3,4,5};
    struct ListNode *head = build_list(arr, 5);
    print_list(reverseList(head));

    return 0;
}