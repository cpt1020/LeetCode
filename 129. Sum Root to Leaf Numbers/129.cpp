#include <vector>
#include <iostream>
#include <cmath>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 129.cpp ../BinaryTree.cpp -std=c++17 -o 129 && ./129
*/

class Solution {
private:
    void dfs(TreeNode* root, vector<vector<int>>& paths, vector<int> tmp) {
        tmp.push_back(root->val);

        if (root->left != nullptr) {
            dfs(root->left, paths, tmp);
        }
        if (root->right != nullptr) {
            dfs(root->right, paths, tmp);
        }
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(tmp);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> paths;
        dfs(root, paths, {});

        vector<int> nums;
        for (auto& path: paths) {
            int tmp {0};
            int powIdx {0};
            for (int i = path.size()-1; i >= 0; --i) {
                tmp += path.at(i) * pow(10, powIdx);
                ++powIdx;
            }
            nums.push_back(tmp);
        }

        int ans {0};
        for (auto& num: nums) {
            ans += num;
        }

        return ans;
    }
};

int main () {

    Solution sol;

    TreeNode* n1_2 = new TreeNode(2);
    TreeNode* n1_3 = new TreeNode(3);
    TreeNode* n1_1 = new TreeNode(1, n1_2, n1_3);
    cout << sol.sumNumbers(n1_1) << endl;

    TreeNode* n2_5 = new TreeNode(5);
    TreeNode* n2_1 = new TreeNode(1);
    TreeNode* n2_9 = new TreeNode(9, n2_5, n2_1);
    TreeNode* n2_0 = new TreeNode(0);
    TreeNode* n2_4 = new TreeNode(4, n2_9, n2_0);
    cout << sol.sumNumbers(n2_4) << endl;

    return 0;
}