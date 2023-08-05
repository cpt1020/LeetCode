#include <iostream>
#include <vector>
#include "../BinaryTree.h"
using namespace std;

class Solution {
private:
    vector<TreeNode*> buildBST(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int i {start}; i <= end; ++i) {
            vector<TreeNode*> left_subtree {buildBST(start, i-1)};
            vector<TreeNode*> right_subtree {buildBST(i+1, end)};

            for (auto& ltree: left_subtree) {
                for (auto& rtree: right_subtree) {
                    TreeNode* node = new TreeNode(i);
                    node->left = ltree;
                    node->right = rtree;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return buildBST(1, n);
    }
};

int main() {

    Solution sol;
    vector<TreeNode*> bst {sol.generateTrees(3)};

    for (const auto& tree: bst) {
        levelOrder(tree);
        cout << endl;
    }

    return 0;
}