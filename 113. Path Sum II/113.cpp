#include <iostream>
#include "../BinaryTree.h"
#include "../utils.h"
using namespace std;

/*
g++ 113.cpp ../BinaryTree.cpp ../utils.cpp -std=c++17 -o 113 && ./113
*/

class Solution {
public:

    void dfs(TreeNode* root, int currSum, const int& targetSum, vector<int> currPath, vector<vector<int>>& ans) {
        currSum += root->val;
        currPath.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr && currSum == targetSum) {
            ans.push_back(currPath);
            return;
        }

        if (root->left != nullptr) {
            dfs(root->left, currSum, targetSum, currPath, ans);
        }
        if (root->right != nullptr) {
            dfs(root->right, currSum ,targetSum, currPath, ans);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        dfs(root, 0, targetSum, {}, ans);
        return ans;
    }
};

int main() {

    Solution sol;

    // case 1
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(1, node2, node3);
    int targetSum {5};
    // ans: []
    print2dVector(sol.pathSum(node1, targetSum));

    // case 2
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n11 = new TreeNode(11, n7, n2);
    TreeNode* n4 = new TreeNode(4, n11, nullptr);
    TreeNode* n5_2 = new TreeNode(5);
    TreeNode* n4_2 = new TreeNode(4, n5_2, n1);
    TreeNode* n13 = new TreeNode(13);
    TreeNode* n8 = new TreeNode(8, n13, n4_2);
    TreeNode* n5 = new TreeNode(5, n4, n8);
    targetSum = 22;
    // ans: [[5,4,11,2],[5,8,4,5]]
    print2dVector(sol.pathSum(n5, targetSum));

    return 0;
}