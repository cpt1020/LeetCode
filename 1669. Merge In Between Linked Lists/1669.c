#include <stdio.h>
#include "../ListNode_C.h"

/*
gcc 1669.c ../ListNode_C.c -o 1669 && ./1669
*/

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *ptr = list1;
    int count = -1;

    struct ListNode *list2_tail = list2;
    while (list2_tail->next != NULL) {
        list2_tail = list2_tail->next;
    }

    struct ListNode *a_node = NULL;
    while (ptr != NULL) {
        ++count;

        if (count == a - 1) {
            a_node = ptr;
        }
        else if (count == a) {
            a_node->next = list2;
        }
        
        if (count == b) {
            list2_tail->next = ptr->next;
            break;
        }

        ptr = ptr->next;
    }
    return list1;
}

int main(int argc, char **argv) {

    int arr1_1 [] = {0,1,2,3,4,5};
    int arr1_2 [] = {1000000,1000001,1000002};
    struct ListNode *head1_1 = build_list(arr1_1, 6);
    struct ListNode *head1_2 = build_list(arr1_2, 3);
    int a = 3;
    int b = 4;
    // Output: [0,1,2,1000000,1000001,1000002,5]
    print_list(mergeInBetween(head1_1, a, b, head1_2));

    int arr2_1 [] = {0,1,2,3,4,5,6};
    int arr2_2 [] = {1000000,1000001,1000002,1000003,1000004};
    struct ListNode *head2_1 = build_list(arr2_1, 7);
    struct ListNode *head2_2 = build_list(arr2_2, 5);
    a = 2;
    b = 5;
    // Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
    print_list(mergeInBetween(head2_1, a, b, head2_2));

    return 0;
}