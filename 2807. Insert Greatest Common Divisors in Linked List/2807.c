#include <stdio.h>
#include <stdlib.h>
#include "../ListNode_C.h"

/*
gcc 2807.c ../ListNode_C.c -o 2807 && ./2807
*/

int GCD(int n1, int n2) {
    if (n2 != 0) {
        return GCD(n2, n1 % n2);
    }
    else {
        return n1;
    }
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    if (head->next == NULL) {
        return head;
    }

    struct ListNode *ptr = head;

    while (ptr->next != NULL) {

        int gcd = GCD(ptr->val, ptr->next->val);
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->val = gcd;
        new->next = ptr->next;
        ptr->next = new;
        ptr = new->next;
    }

    return head;
}

int main(int argc, char **argv) {

    int arr [] = {18,6,10,3};
    struct ListNode *head = build_list(arr, 4);
    // Output: [18,6,6,2,10,1,3]
    print_list(insertGreatestCommonDivisors(head));

    return 0;
}