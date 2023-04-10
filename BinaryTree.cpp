#include "BinaryTree.h"
#include <iostream>
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