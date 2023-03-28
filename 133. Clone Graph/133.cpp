#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if (node == nullptr){
        return nullptr;
    }

    unordered_map<Node*, Node*> umap;
    // for checking a node has been copied or not
    // in order to avoid copying a node many times
    // umap[original_node] = copied_node

    Node* copied = new Node(node->val);
    umap[node] = copied;

    // use BFS to traverse the graph
    queue<Node*> q;
    q.push(node);
    while (q.empty() != true){
        Node* ptr {q.front()};
        q.pop();

        for(auto neighbor: ptr->neighbors){
            if (umap.find(neighbor) == umap.end()){
                // if the neighbor hasn't been copied
                // copy the neighbor
                Node* newNode = new Node(neighbor->val);
                umap[neighbor] = newNode;

                q.push(neighbor);
                // push the neighbor to queue
            }
            umap[ptr]->neighbors.push_back(umap[neighbor]);
        }
    }
    return copied;
}

int main(){

    return 0;
}