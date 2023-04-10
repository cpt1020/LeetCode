#include <iostream>
#include <vector>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 99.cpp ../BinaryTree.cpp -std=c++17 -o 99 && ./99
*/

class Solution {
public:

    void inorder(TreeNode* root, vector<TreeNode*>& vec) {
        if (root->left != nullptr) {
            inorder(root->left, vec);
        }
        vec.push_back(root);
        if (root->right != nullptr) {
            inorder(root->right, vec);
        }
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;

        inorder(root, vec);

        int bigIdx {0};
        int smallIdx {0};

        for (int i {0}; i < vec.size()-1; ++i) {
            if (vec.at(i)->val > vec.at(i+1)->val) {
                bigIdx = i;
                break;
            }
        }

        for (int i = vec.size() - 1; i > 0; --i) {
            if (vec.at(i)->val < vec.at(i-1)->val) {
                smallIdx = i;
                break;
            }
        }

        int tmp {vec.at(bigIdx)->val};
        vec.at(bigIdx)->val = vec.at(smallIdx)->val;
        vec.at(smallIdx)->val = tmp;
    }
};

int main() {

    Solution sol;

    // case 1
    cout << "case 1" << endl;
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3, nullptr, n2);
    TreeNode* n1 = new TreeNode(1, n3, nullptr);    // head of case 1
    cout << "Before Recover: " << endl;
    n1->printInorder(n1);
    cout << "\nAfter Recover: " << endl;
    sol.recoverTree(n1);
    n1->printInorder(n1);
    cout << endl;

    // case 2
    cout << "\ncase 2" << endl;
    TreeNode* n2_2 = new TreeNode(2);
    TreeNode* n2_4 = new TreeNode(4, n2_2, nullptr);
    TreeNode* n2_1 = new TreeNode(1);
    TreeNode* n2_3 = new TreeNode(3, n2_1, n2_4);   // head of case 2
    cout << "Before Recover: " << endl;
    n2_3->printInorder(n2_3);
    cout << "\nAfter Recover: " << endl;
    sol.recoverTree(n2_3);
    n2_3->printInorder(n2_3);
    cout << endl;

    return 0;
}