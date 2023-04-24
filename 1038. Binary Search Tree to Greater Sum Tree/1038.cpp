#include <iostream>
#include <vector>
#include <iostream>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 1038.cpp ../BinaryTree.cpp -std=c++17 -o 1038 && ./1038
*/

class Solution {
private:

    void inorderTraversal(TreeNode* root, vector<TreeNode*>& inorder) {
        if (root->left != nullptr) {
            inorderTraversal(root->left, inorder);
        }

        inorder.push_back(root);

        if (root->right != nullptr) {
            inorderTraversal(root->right, inorder);
        }
    }

public:

    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> inorder;
        inorderTraversal(root, inorder);
        for (int i = inorder.size() - 2; i >= 0; --i) {
            inorder.at(i)->val += inorder.at(i+1)->val;
        }
        return root;
    }
};

int main() {

    Solution sol;

    TreeNode* n3 = new TreeNode(3);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(2, nullptr, n3);
    TreeNode* n1 = new TreeNode(1, n0, n2);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7, nullptr, n8);
    TreeNode* n6 = new TreeNode(6, n5, n7);
    TreeNode* n4 = new TreeNode(4, n1, n6);
    levelOrder(sol.bstToGst(n4));

    return 0;
}