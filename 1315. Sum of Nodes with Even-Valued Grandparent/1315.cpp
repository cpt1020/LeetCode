#include <vector>
#include <iostream>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 1315.cpp ../BinaryTree.cpp -std=c++17 -o 1315 && ./1315
*/

class Solution {
private:

    void dfs(TreeNode* root, int& ans, int grandparent, int parent) {
        if (grandparent != 0 && grandparent % 2 == 0) {
            ans += root->val;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            dfs(root->left,ans, parent, root->val);
        }
        if (root->right != nullptr) {
            dfs(root->right,ans, parent, root->val);
        }
    }

public:

    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }

        int ans {0};

        dfs(root, ans, 0, 0);

        return ans;
    }
};

int main() {

    Solution sol;

    TreeNode* n1_9 = new TreeNode(9);
    TreeNode* n1_1 = new TreeNode(1);
    TreeNode* n1_4 = new TreeNode(4);
    TreeNode* n1_5 = new TreeNode(5);
    TreeNode* n1_2 = new TreeNode(2, n1_9, nullptr);
    TreeNode* n1_7 = new TreeNode(7, n1_1, n1_4);
    TreeNode* n1_1_2 = new TreeNode(1);
    TreeNode* n1_3 = new TreeNode(3, nullptr, n1_5);
    TreeNode* n1_7_2 = new TreeNode(7, n1_2, n1_7);
    TreeNode* n1_8 = new TreeNode(8, n1_1_2, n1_3);
    TreeNode* n1_6 = new TreeNode(6, n1_7_2, n1_8);
    // Output: 18
    cout << sol.sumEvenGrandparent(n1_6) << endl;

    TreeNode* n2_1 = new TreeNode(1);
    // Output: 0
    cout << sol.sumEvenGrandparent(n2_1) << endl;

    return 0;
}