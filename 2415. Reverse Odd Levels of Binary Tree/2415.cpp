#include <vector>
#include <queue>
#include <iostream>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 2415.cpp ../BinaryTree.cpp -std=c++17 -o 2415 && ./2415
*/

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level {0};
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() != true) {
            int size = q.size();

            if (level % 2 == 0) {
                for (int i {0}; i < size; ++i) {
                    TreeNode* curNode {q.front()};
                    q.pop();

                    if (curNode->left != nullptr) {
                        q.push(curNode->left);
                    }
                    if (curNode->right != nullptr) {
                        q.push(curNode->right);
                    }
                }
            }
            else {
                vector<TreeNode*> tmp (size);
                vector<int> tmpVal (size);
                for (int i {0}; i < size; ++i) {
                    TreeNode* curNode {q.front()};
                    q.pop();
                    tmp.at(i) = curNode;
                    tmpVal.at(i) = curNode->val;

                    if (curNode->left != nullptr) {
                        q.push(curNode->left);
                    }
                    if (curNode->right != nullptr) {
                        q.push(curNode->right);
                    }
                }

                for (int i {0}; i < size; ++i) {
                    tmp.at(i)->val = tmpVal.at(size-1-i);
                }
            }
            
            level += 1;
        }

        return root;
    }
};

int main() {

    Solution sol;

    TreeNode* n1_8 = new TreeNode(8);
    TreeNode* n1_13 = new TreeNode(13);
    TreeNode* n1_21 = new TreeNode(21);
    TreeNode* n1_34 = new TreeNode(34);
    TreeNode* n1_3 = new TreeNode(3, n1_8, n1_13);
    TreeNode* n1_5 = new TreeNode(5, n1_21, n1_34);
    TreeNode* n1_2 = new TreeNode(2, n1_3, n1_5);
    // Output: [2,5,3,8,13,21,34]
    levelOrder(n1_2);
    sol.reverseOddLevels(n1_2);
    levelOrder(n1_2);

    TreeNode* n2_13 = new TreeNode(13);
    TreeNode* n2_11 = new TreeNode(11);
    TreeNode* n2_7 = new TreeNode(7, n2_13, n2_11);
    // Output: [7,11,13]
    cout << endl;
    levelOrder(n2_7);
    sol.reverseOddLevels(n2_7);
    levelOrder(n2_7);

    return 0;
}