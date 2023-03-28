#include "../BinaryTree.h"
#include "../utils.h"
#include <vector>
#include <queue>
using namespace std;

/*
g++ 199_DFS.cpp ../BinaryTree.cpp ../utils.cpp -std=c++17 -o 199_DFS && ./199_DFS
*/

void dfs(TreeNode* root, vector<int>& ans, int level){
    if (root == nullptr){
        return;
    }

    if (ans.size() == level){
        ans.push_back(root->val);
    }

    dfs(root->right, ans, level+1);
    dfs(root->left, ans, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    dfs(root, ans, 0);
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