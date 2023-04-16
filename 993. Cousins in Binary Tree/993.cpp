#include <vector>
#include <queue>
#include <iostream>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 993.cpp ../BinaryTree.cpp -std=c++17 -o 993 && ./993
*/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() != true) {
            int size = q.size();
            bool hasX {false};
            bool hasY {false};
            vector<int> n;

            for (int i {0}; i < size; i++) {
                TreeNode* node {q.front()};
                n.push_back(node->val);

                if (node->val == x) {
                    hasX = true;
                }
                if (node->val == y) {
                    hasY = true;
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                else {
                    TreeNode* nullNode = new TreeNode(0);
                    q.push(nullNode);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                else {
                    TreeNode* nullNode = new TreeNode(0);
                    q.push(nullNode);
                }

                q.pop();
            }
            
            if (hasX == true && hasY == true) {
                int xIdx {-1};
                int yIdx {-1};
                for (int i {0}; i < n.size(); ++i) {
                    if (n.at(i) == x) {
                        xIdx = i;
                    }
                    if (n.at(i) == y) {
                        yIdx = i;
                    }
                }

                if (abs(xIdx - yIdx) == 1) {
                    if (min(xIdx, yIdx)%2==0) {
                        return false;
                    }
                    else {
                        return true;
                    }
                }
                else {
                    return true;
                }
            }
            else if (hasX || hasY) {
                return false;
            }
        }

        return false;
    }
};

int main() {

    Solution sol;
    TreeNode* n1_4 = new TreeNode(4);
    TreeNode* n1_2 = new TreeNode(2, n1_4, nullptr);
    TreeNode* n1_3 = new TreeNode(3);
    TreeNode* n1_1 = new TreeNode(1, n1_2, n1_3);
    cout << boolalpha << sol.isCousins(n1_1, 4, 3) << endl;

    TreeNode* n2_4 = new TreeNode(4);
    TreeNode* n2_5 = new TreeNode(5);
    TreeNode* n2_2 = new TreeNode(2, nullptr, n2_4);
    TreeNode* n2_3 = new TreeNode(3, nullptr, n2_5);
    TreeNode* n2_1 = new TreeNode(1, n2_2, n2_3);
    cout << boolalpha << sol.isCousins(n2_1, 5, 4) << endl;
 
    return 0;
}