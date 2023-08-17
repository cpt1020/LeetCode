class Solution {
public:

    Node* connect_queue(Node* root) {
        if (root == nullptr) {
            return root;
        }

        queue<Node *> q;
        q.push(root);

        int node {1};

        Node *prev {nullptr};
        Node *cur {q.front()};

        while (q.empty() != true) {
            
            for (int i {0}; i < node; ++i) {
                q.pop();
                cur->next = prev;

                if (cur->right != nullptr) {
                    q.push(cur->right);
                    q.push(cur->left);
                }

                prev = cur;
                cur = q.front();
            }

            prev = nullptr;

            node *= 2;
        }

        return root;
    }

    Node* connect_deque(Node* root) {
        if (root == nullptr) {
            return root;
        }

        deque<Node *> dq;
        dq.push_back(root);

        while (dq.empty() != true) {
            int size = dq.size();

            for (int i {0}; i < size; ++i) {
                dq.at(i)->next = (i < size - 1) ? dq.at(i+1) : nullptr;

                if (dq.at(i)->left != nullptr) {
                    dq.push_back(dq.at(i)->left);
                    dq.push_back(dq.at(i)->right);
                }
            }

            for (int i {0}; i < size; ++i) {
                dq.pop_front();
            }
        }

        return root;
    }
};