#include <queue>
#include <iostream>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 1302.cpp ../BinaryTree.cpp -std=c++17 -o 1302 && ./1302
*/

class Solution {
private:

    void dfs_findLevel(TreeNode* root, int& deepestLevel, int curLevel) {
        curLevel += 1;
        deepestLevel = max(deepestLevel, curLevel);

        if (root->left != nullptr) {
            dfs_findLevel(root->left, deepestLevel, curLevel);
        }
        if (root->right != nullptr) {
            dfs_findLevel(root->right, deepestLevel, curLevel);
        }
    }

    void dfs_findSum(TreeNode* root, int& deepestLevel, int curLevel, int& sum) {
        curLevel += 1;
        if (curLevel == deepestLevel) {
            sum += root->val;
        }

        if (root->left != nullptr) {
            dfs_findSum(root->left, deepestLevel, curLevel, sum);
        }
        if (root->right != nullptr) {
            dfs_findSum(root->right, deepestLevel, curLevel, sum);
        }
    }

    void dfs(TreeNode* root, int& deepestLevel, int curLevel, int& sum) {
        curLevel += 1;
        
        if (root->left == nullptr && root->right == nullptr) {
            if (curLevel > deepestLevel) {
                deepestLevel = curLevel;
                sum = root->val;
            }
            else if (curLevel == deepestLevel) {
                sum += root->val;
            }
        }
        else {
            if (root->left != nullptr) {
                dfs(root->left, deepestLevel, curLevel, sum);
            }
            if (root->right != nullptr) {
                dfs(root->right, deepestLevel, curLevel, sum);
            }
        }
    }

public:

    int deepestLeavesSum_BFS(TreeNode* root) {
        int res {0};
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() != true) {
            int size = q.size();
            int sum {0};
            for (int i {0}; i < size; ++i) {
                TreeNode* node {q.front()};
                q.pop();
                sum += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res = sum;
        }
        return res;
    }

    int deepestLeavesSum_DFS(TreeNode* root) {
        int deepestLevel {0};
        dfs_findLevel(root, deepestLevel, 0);
        int sum {0};
        dfs_findSum(root, deepestLevel, 0, sum);
        return sum;
    }

    int deepestLeavesSum_DFS_optimized(TreeNode* root) {
        int deepestLevel {0};
        int sum {0};
        dfs(root, deepestLevel, 0, sum);
        return sum;
    }

};

int main() {

    Solution sol;

    TreeNode* n1_7 = new TreeNode(7);
    TreeNode* n1_8 = new TreeNode(8);
    TreeNode* n1_5 = new TreeNode(5);
    TreeNode* n1_4 = new TreeNode(4, n1_7, nullptr);
    TreeNode* n1_6 = new TreeNode(6, nullptr, n1_8);
    TreeNode* n1_2 = new TreeNode(2, n1_4, n1_5);
    TreeNode* n1_3 = new TreeNode(3, nullptr, n1_6);
    TreeNode* n1_1 = new TreeNode(1, n1_2, n1_3);
    // ans: 15
    cout << sol.deepestLeavesSum_BFS(n1_1) << endl;
    cout << sol.deepestLeavesSum_DFS(n1_1) << endl;
    cout << sol.deepestLeavesSum_DFS_optimized(n1_1) << endl;

    return 0;
}