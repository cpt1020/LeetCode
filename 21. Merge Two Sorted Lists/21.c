#include <stdio.h>
#include "../ListNode_C.h"

/*
gcc 21.c ../ListNode_C.c -o 21 && ./21
*/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL || list2 == NULL) {
        return (list1 == NULL) ? list2 : list1;
    }

    struct ListNode *head = NULL;

    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    }
    else {
        head = list2;
        list2 = list2->next;
    }

    struct ListNode *ptr = head;

    while (list1 != NULL || list2 != NULL) {
        if (list1 == NULL) {
            ptr->next = list2;
            break;
        }
        else if(list2 == NULL){
            ptr->next = list1;
            break;
        }

        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        }
        else { 
            ptr->next = list2;
            list2 = list2->next;
        }

        ptr = ptr->next;
    }

    return head;
}

int main(int argc, char **argv) {

    int arr1 [] = {1,2,4};
    int arr2 [] = {1,3,4};
    struct ListNode *list1 = build_list(arr1, 3);
    struct ListNode *list2 = build_list(arr2, 3);

    print_list(mergeTwoLists(list1, list2));

    return 0;
}