#include "../ListNode.h"
#include <vector>
#include <iostream>
using namespace std;

/*
g++ 19.cpp ../ListNode.cpp -std=c++17 -o 19 && ./19
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> list;
        ListNode* ptr {head};
        while (ptr != nullptr) {
            list.push_back(ptr);
            ptr = ptr->next;
        }

        if (list.size() == 1) {
            return nullptr;
        }

        if (n == 1) {
            list.at(list.size() - 2)->next = nullptr;
        }
        else if (n == (list.size())) {
            head = list.at(1);
        }
        else {
            int index {static_cast<int>(list.size()) - n};
            list.at(index - 1)->next = list.at(index + 1);
        }
        return head;
        
        // // 先算總共有多少node
        // int node_num {0};
        // ListNode* ptr = head;
        // while (ptr != nullptr){
        //     node_num += 1;
        //     ptr = ptr->next;
        // }

        // // 若只有一個node，那就return nullptr
        // if (node_num == 1 && n == 1){
        //     // delete head;
        //     return nullptr;
        // }

        // // 目標node的前一個node的node編號
        // int node_before_target {node_num - n};
        // // 若要刪掉的node是第一個node，就把head指向head的next
        // if (node_before_target == 0){
        //     // ptr = head;
        //     head = head->next;
        //     // delete ptr;
        //     return head;
        // }

        // int node_count {1};
        // ptr = head;
        // while (node_count != node_before_target){
        //     ptr = ptr->next;
        //     node_count += 1;
        // }
        // // ListNode* target = ptr->next;
        // ptr->next = ptr->next->next;
        // // delete target;
        // return head;
    }
};

int main() {

    ListNode* five = new ListNode(5);
    ListNode* four = new ListNode(4, five);
    ListNode* three = new ListNode(3, four);
    ListNode* two = new ListNode(2, three);
    ListNode* one = new ListNode(1, two);

    Solution sol;
    printList(sol.removeNthFromEnd(one, 2));

    return 0;
}