#include <vector>
#include <algorithm>
#include <iostream>
#include "../ListNode.h"
using namespace std;

/*
g++ 23.cpp ../ListNode.cpp -std=c++17 -o 23 && ./23
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return nullptr;
        }

        vector<ListNode*> nodes;
        for (auto node: lists) {
            while (node != nullptr) {
                nodes.push_back(node);
                node = node->next;
            }
        }

        if (nodes.size() == 0) {
            return nullptr;
        }

        sort(nodes.begin(), nodes.end(), [](ListNode* a, ListNode* b){return a->val < b->val;});

        ListNode* head {nodes.at(0)};
        for (int i {0}; i < nodes.size() - 1; ++i) {
            nodes.at(i)->next = nodes.at(i + 1);
        }
        nodes.at(nodes.size()-1)->next = nullptr;

        return head;
    }
};

int main() {

    Solution sol;

    ListNode* node1_3 = new ListNode(5);
    ListNode* node1_2 = new ListNode(4, node1_3);
    ListNode* node1_1 = new ListNode(1, node1_2);
    ListNode* node2_3 = new ListNode(10);
    ListNode* node2_2 = new ListNode(3, node2_3);
    ListNode* node2_1 = new ListNode(1, node2_2);
    ListNode* node3_3 = new ListNode(7);
    ListNode* node3_2 = new ListNode(6, node3_3);
    ListNode* node3_1 = new ListNode(2, node3_2);
    vector<ListNode*> lists {node1_1, node2_1, node3_1};
    printList(sol.mergeKLists(lists));

    return 0;
}