// Problem: Validate Binary Search Tree
// Difficulty: Medium
// Topic: DFS
// LeetCode URL: https://leetcode.com/problems/validate-binary-search-tree

// Approach:
// Use DFS with range constraints to validate the BST.
// For each node, ensure its value lies within a valid (min, max) range.
// Initially, the range is (-∞, +∞).
// For the left subtree, update max to current node's value.
// For the right subtree, update min to current node's value.
// If any node violates the range, return false.
// If all nodes satisfy the constraints, return true.

// Time Complexity: O(n)
// Space Complexity: O(log n) — for balanced tree (height = log n) & O(n) — for skewed tree (height = n)

class Solution {
public:
    bool dfs(TreeNode* root, long min_val, long max_val) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }
        return (dfs(root->left, min_val, root->val) &&
                dfs(root->right, root->val, max_val));
    }
    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }
};