#include <iostream>
#include <vector>
#include "../BinaryTree.h"
using namespace std;

class Solution {
private:

    void preorder(TreeNode* root, vector<int>& list) {
        list.push_back(root->val);

        if (root->left != nullptr) {
            preorder(root->left, list);
        }
        if (root->right != nullptr) {
            preorder(root->right, list);
        }
    }
public:

    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }

        vector<int> preorder_list;
        preorder(root, preorder_list);
        TreeNode *ptr = root;

        for (int i {0}; i < preorder_list.size(); ++i) {
            ptr->left = nullptr;
            ptr->val = preorder_list.at(i);

            if (ptr->right == nullptr && (i != preorder_list.size() - 1)) {
                TreeNode *r_node = new TreeNode();
                ptr->right = r_node;
            }
            
            ptr = ptr->right;
        }
    }
};

int main() {


    return 0;
}