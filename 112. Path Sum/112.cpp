#include <iostream>
#include "../BinaryTree.h"
using namespace std;

class Solution {
public:

    void dfs(TreeNode* root, int currSum, const int& targetSum, bool& res) {
        currSum += root->val;

        if (root->left == nullptr && root->right == nullptr && currSum == targetSum) {
            res = true;
            return;
        }

        if (root->left != nullptr) {
            dfs(root->left, currSum, targetSum, res);
        }
        if (root->right != nullptr) {
            dfs(root->right, currSum, targetSum, res);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        bool res {false};
        dfs(root, 0, targetSum, res);
        return res;
    }
};

int main() {

    Solution sol;

    // case 1
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(1, node2, node3);
    int targetSum {5};
    // ans: false
    cout << boolalpha << sol.hasPathSum(node1, targetSum) << endl;

    // case 2
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n11 = new TreeNode(11, n7, n2);
    TreeNode* n4 = new TreeNode(4, n11, nullptr);
    TreeNode* n4_2 = new TreeNode(4, nullptr, n1);
    TreeNode* n13 = new TreeNode(13);
    TreeNode* n8 = new TreeNode(8, n13, n4_2);
    TreeNode* n5 = new TreeNode(5, n4, n8);
    targetSum = 22;
    // ans: true
    cout << boolalpha << sol.hasPathSum(n5, targetSum) << endl;

    return 0;
}