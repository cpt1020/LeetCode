#ifndef BINARYTREE_H
#define BINARYTREE_H

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);

    void printInorder(TreeNode* root);
};

void levelOrder(TreeNode* root);

#endif