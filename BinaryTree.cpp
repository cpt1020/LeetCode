#include "BinaryTree.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode::TreeNode() {
    val = 0;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) {
    val = x;
    this->left = left;
    this->right = right;
}

void TreeNode::printInorder(TreeNode* root) {
    if (root->left != nullptr) {
        root->printInorder(root->left);
    }
    cout << root->val << " ";
    if (root->right != nullptr) {
        root->printInorder(root->right);
    }
}

void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() != true) {
        int q_size = q.size();
        for (int i {0}; i < q_size; ++i) {
            cout << q.front()->val << " ";
            if (q.front()->left != nullptr) {
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr) {
                q.push(q.front()->right);
            }
            q.pop();
        }
        cout << endl;
    }
}