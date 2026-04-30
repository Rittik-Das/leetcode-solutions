// Problem: Maximum Width of Binary Tree
// Difficulty: Medium
// Topic: BFS
// LeetCode URL: https://leetcode.com/problems/maximum-width-of-binary-tree

// Approach:
// Assign indices to nodes as if it's a complete binary tree.
// Use BFS to process nodes level by level.
// For each level, track first and last node indices.
// Width = last index - first index + 1.
// Normalize indices at each level to prevent overflow.
// Keep updating the maximum width across all levels.

// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        // left = (2*i+1)
        // right = (2*i+2)

        // To start every level index from revised formula
        // left = (2*i+1) - 1 = 2*i
        // right = (2*i+2) - 1 = 2*i + 1
        int max_width = 1;

        while (!q.empty()) {
            int no_of_nodes_in_level = q.size();
            int i;
            long long starting_index = q.front().second;
            // int ending_index = q.back().second;
            long long updated_first, updated_last;

            for (i = 0; i < no_of_nodes_in_level; i++) {
                auto curr = q.front().first;
                auto curr_index = q.front().second;
                q.pop();

                curr_index = curr_index - starting_index;

                if (i == 0) {
                    updated_first = curr_index;
                }
                if (i == no_of_nodes_in_level - 1) {
                    updated_last = curr_index;
                }

                if (curr->left != NULL) {
                    q.push({curr->left, (2 * curr_index)});
                }
                if (curr->right != NULL) {
                    q.push({curr->right, ((2 * curr_index) + 1)});
                }
            }
            max_width = max(max_width, (int)(updated_last - updated_first + 1));
        }
        return max_width;
    }
};