#include <stdio.h>
#include "../ListNode_C.h"

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, char **argv) {

    int list_node [] = {1, 2, 3, 4, 5};
    struct ListNode *head = build_list(list_node, 5);
    // print_list(head);
    
    printf("%d\n", middleNode(head)->val);

    return 0;
}