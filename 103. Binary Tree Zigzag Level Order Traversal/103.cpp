#include <deque>
#include <queue>
#include <vector>
#include <iostream>
#include "../BinaryTree.h"
#include "../utils.h"
using namespace std;

/*
g++ 103.cpp ../utils.cpp ../BinaryTree.cpp -std=c++17 -o 103 && ./103
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder_deque(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        int level {0};
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while (dq.empty() != true) {
            int size = dq.size();
            vector<int> tmp;
            
            if (level % 2 == 0) {
                for (int i {0}; i < size; ++i) {
                    TreeNode* node {dq.front()};
                    dq.pop_front();
                    tmp.push_back(node->val);

                    if (node->left != nullptr) {
                        dq.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        dq.push_back(node->right);
                    }
                }
            }
            else {
                for (int i {0}; i < size; ++i) {
                    TreeNode* node {dq.back()};
                    dq.pop_back();
                    tmp.push_back(node->val);

                    if (node->right != nullptr) {
                        dq.push_front(node->right);
                    }
                    if (node->left != nullptr) {
                        dq.push_front(node->left);
                    }
                }
            }

            ans.push_back(tmp);
            level += 1;
        }

        return ans;
    }

    vector<vector<int>> zigzagLevelOrder_queue(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        int level {0};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() != true) {
            int size = q.size();
            vector<int> tmp(size, 0);

            for (int i {0}; i < size; ++i) {
                TreeNode* node {q.front()};
                q.pop();

                if (level % 2 == 0){
                    tmp.at(i) = node->val;
                }
                else {
                    tmp.at(size - 1 - i) = node->val;
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.push_back(tmp);
            level += 1;
        }

        return ans;
    }
};

int main() {

    Solution sol;

    TreeNode* n1_15 = new TreeNode(15);
    TreeNode* n1_7 = new TreeNode(7);
    TreeNode* n1_9 = new TreeNode(9);
    TreeNode* n1_20 = new TreeNode(20, n1_15, n1_7);
    TreeNode* n1_3 = new TreeNode(3, n1_9, n1_20);
    // Output: [[3],[20,9],[15,7]]
    print2dVector<int>(sol.zigzagLevelOrder_deque(n1_3));
    print2dVector<int>(sol.zigzagLevelOrder_queue(n1_3));

    TreeNode* n2_1 = new TreeNode(1);
    // Output: [[1]]
    print2dVector<int>(sol.zigzagLevelOrder_deque(n2_1));
    print2dVector<int>(sol.zigzagLevelOrder_queue(n2_1));

    // Output: []
    print2dVector<int>(sol.zigzagLevelOrder_deque(nullptr));
    print2dVector<int>(sol.zigzagLevelOrder_queue(nullptr));

    return 0;
}