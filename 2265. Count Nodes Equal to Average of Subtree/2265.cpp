#include <iostream>
#include <utility>
#include <cmath>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 2265.cpp ../BinaryTree.cpp -std=c++17 -o 2265 && ./2265
*/

class Solution {
private:

    pair<int, int> dfs(TreeNode *root, int& ans, int cur_sum, int cur_node_num) {
        pair<int, int> left_subtree {0, 0};
        if (root->left != nullptr) {
            left_subtree = dfs(root->left, ans, cur_sum, cur_node_num);
        }
        pair<int, int> right_subtree {0, 0};
        if (root->right != nullptr) {
            right_subtree = dfs(root->right, ans, cur_sum, cur_node_num);
        }

        cur_sum = root->val + left_subtree.first + right_subtree.first;
        cur_node_num = left_subtree.second + right_subtree.second + 1;

        if (root->val == floor(cur_sum/cur_node_num)) {
            ans += 1;
        }

        return {cur_sum, cur_node_num};
    }

public:

    int averageOfSubtree(TreeNode* root) {
        int ans {0};
        dfs(root, ans, 0, 0);
        return ans;
    }
};

int main() {

    Solution sol;

    TreeNode n0 = TreeNode(0);
    TreeNode n1 = TreeNode(1);
    TreeNode n6 = TreeNode(6);
    TreeNode n5 = TreeNode(5, nullptr, &n6);
    TreeNode n8 = TreeNode(8, &n0, &n1);
    TreeNode root = TreeNode(4, &n8, &n5);

    cout << sol.averageOfSubtree(&root) << endl;

    return 0;
}