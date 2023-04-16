#include <vector>
#include <queue>
#include <iostream>
#include "../BinaryTree.h"
using namespace std;

/*
g++ 2641.cpp ../BinaryTree.cpp -std=c++17 -o 2641 && ./2641
*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        if (root->left == nullptr && root->right == nullptr) {
            root->val =0;
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.empty() != true) {
            
            int node_num = q.size();
            vector<TreeNode*> nodes;
            vector<int> vals;
            
            while (q.empty() != true) {
                nodes.push_back(q.front());
                vals.push_back(q.front()->val);
                q.pop();
            }

            if (node_num == 1) {
                nodes.at(0)->val = 0;
            }
            else {

                int sum {0};
                for (auto n: vals) {
                    if (n != -1) {
                        sum += n;
                    }
                }

                int i {0};
                while (i < node_num) {
                    
                    if (nodes.at(i)->val != -1 && i % 2 == 0) {
                        int res {sum};
                        if (vals.at(i+1) != -1) {
                            res -= (vals.at(i) + vals.at(i+1));
                        }
                        else {
                            res -= (vals.at(i));
                        }
                        nodes.at(i)->val = res;
                    }
                    else if (nodes.at(i)->val != -1 && i % 2 == 1) {
                        int res {sum};
                        if (vals.at(i-1) != -1) {
                            res -= (vals.at(i) + vals.at(i-1));
                        }
                        else {
                            res -= (vals.at(i));
                        }
                        nodes.at(i)->val = res;
                    }
                    
                    i++;
                }
            }

            for (TreeNode* n: nodes) {
                if (n->val != -1 && (n->left != nullptr || n->right != nullptr)) {
                    if (n->left == nullptr) {
                        TreeNode* nullNode = new TreeNode(-1);
                        q.push(nullNode);
                    }
                    else {
                        q.push(n->left);
                    }
                    
                    if (n->right == nullptr) {
                        TreeNode* nullNode = new TreeNode(-1);
                        q.push(nullNode);
                    }
                    else {
                        q.push(n->right);
                    }
                }
            }   
        }
        
        return root;
    }
};


int main() {

    Solution sol;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n10 = new TreeNode(10);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4, n1, n10);
    TreeNode* n9 = new TreeNode(9, nullptr, n7);
    TreeNode* n5 = new TreeNode(5, n4, n9);

    levelOrder(n5);
    n5 = sol.replaceValueInTree(n5);
    cout << "\nAfter replaceValueInTree():" << endl;
    levelOrder(n5);

    return 0;
}