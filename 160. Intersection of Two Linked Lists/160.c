#include <stdio.h>
#include <stdbool.h>    // for true/false
#include "../ListNode_C.h"

/*
gcc 160.c ../ListNode_C.c -o 160 && ./160
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptr1 = headA, *ptr2 = headB;

    while (true) {
        if (ptr1 != NULL && ptr2 != NULL && ptr1 == ptr2) {
            return ptr1;
        }

        if (ptr1 == NULL && ptr2 == NULL) {
            return NULL;
        }
        else if (ptr1 == NULL && ptr2 != NULL) {
            ptr1 = headB;
            ptr2 = ptr2->next;
        }
        else if (ptr1 != NULL && ptr2 == NULL) {
            ptr2 = headA;
            ptr1 = ptr1->next;
        }
        else {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

    }
}

void print_res(struct ListNode *ans) {
    if (ans != NULL) {
        printf("%d\n", ans->val);
    }
    else {
        print_list("No intersection\n");
    }
}

int main(int argc, char **argv) {

    int arr1_1 [] = {4,1,8,4,5};
    int arr1_2 [] = {5,6,1};
    struct ListNode *head1_1 = build_list(arr1_1, 5);
    struct ListNode *head1_2 = build_list(arr1_2, 3);
    head1_2->next->next->next = head1_1->next->next;
    print_res(getIntersectionNode(head1_1, head1_2));

    return 0;
}