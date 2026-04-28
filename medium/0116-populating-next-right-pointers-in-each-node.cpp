// Problem: Populating Next Right Pointers in Each Node
// Difficulty: Medium
// Topic: BFS
// LeetCode URL: https://leetcode.com/problems/populating-next-right-pointers-in-each-node

// Approach:
// Use level order traversal (BFS) with a queue.
// For each level, process all nodes one by one.
// Keep track of the previous node and connect it to the current node using next pointer.
// Push left and right children of each node into the queue.
// At the end of each level, the last node points to NULL.
// Finally, return the root.

// Time Complexity: O(n)
// Space Complexity: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int no_of_nodes_in_level = q.size();
            // Node *current = q.front();
            // q.pop();
            Node* previous = NULL;
            int i;

            for (i = 0; i < no_of_nodes_in_level; i++) {
                Node* current = q.front();
                q.pop();
                if (previous != NULL) {
                    previous->next = current;
                }
                previous = current;
                if (current->left != NULL) {
                    q.push(current->left);
                }
                if (current->right != NULL) {
                    q.push(current->right);
                }
            }
        }
        return root;
    }
};