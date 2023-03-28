#include "../BinaryTree.h"
#include "../utils.h"
#include <vector>
#include <queue>
using namespace std;

/*
g++ 199_BFS.cpp ../BinaryTree.cpp ../utils.cpp -std=c++17 -o 199_BFS && ./199_BFS
*/

vector<int> rightSideView(TreeNode* root) {
    // Use level-order traversal (BFS)

    if (root == nullptr){
        return {};
    }

    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() != true){
        int size {static_cast<int>(q.size())};
        // this step is important

        for (int i {0}; i < size; ++i){
            TreeNode* node {q.front()};
            q.pop();

            if (i == size - 1){
                ans.push_back(node->val);
            }

            // push left child first
            if (node->left != nullptr){
                q.push(node->left);
            }
            // then push right child
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
    }

    return ans;
}

int main(){

    TreeNode one {TreeNode(1)};
    TreeNode two {TreeNode(2)};
    TreeNode three {TreeNode(3)};
    TreeNode four {TreeNode(4)};
    TreeNode five {TreeNode(5)};

    one.left = &two;
    one.right = &three;
    two.right = &five;
    three.right = &four;
    
    printVector(rightSideView(&one));
    
    return 0;
}