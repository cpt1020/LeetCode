#include "../BinaryTree.h"
#include <iostream>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q){
        return root;
    }

    TreeNode* left {lowestCommonAncestor(root->left, p, q)};
    TreeNode* right {lowestCommonAncestor(root->right, p, q)};

    if (left != nullptr && right != nullptr){
        return root;
    }
    if (left == nullptr && right == nullptr){
        return nullptr;
    }

    if (left == nullptr){
        return right;
    }
    else{
        return left;
    }
}

int main(){

    TreeNode three {TreeNode(3)};
    TreeNode five {TreeNode(5)};
    TreeNode one {TreeNode(1)};
    TreeNode six {TreeNode(6)};
    TreeNode two {TreeNode(2)};
    TreeNode seven {TreeNode(7)};
    TreeNode four {TreeNode(4)};
    TreeNode zero {TreeNode(0)};
    TreeNode eight {TreeNode(8)};

    three.left = &five;
    three.right = &one;
    five.left = &six;
    five.right = &two;
    two.left = &seven;
    two.right = &four;
    one.left = &zero;
    one.right = &eight;

    cout << lowestCommonAncestor(&three, &five, &one)->val << endl;    

    return 0;
}