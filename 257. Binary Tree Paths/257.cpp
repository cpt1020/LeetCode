#include <iostream>
#include <string>
#include <vector>
#include "../BinaryTree.h"
#include "../utils.h"
using namespace std;

/*
g++ 257.cpp ../BinaryTree.cpp ../utils.cpp -std=c++17 -o 257 && ./257
*/

class Solution {
public:

    void dfs(TreeNode* root, vector<string>& ans, string currStr) {
        currStr += "->";
        currStr += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(currStr.substr(2, currStr.size() - 2));
        }

        if (root->left != nullptr) {
            dfs(root->left, ans, currStr);
        }
        if (root->right != nullptr) {
            dfs(root->right, ans, currStr);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, ans, "");
        return ans;
    }
};

int main() {

    Solution sol;

    // case 1
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(2, nullptr, n5);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n1 = new TreeNode(1, n2, n3);
    // ans: ["1->2->5","1->3"]
    printVector(sol.binaryTreePaths(n1));
 
    return 0;
}