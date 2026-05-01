// Problem: Sum Root to Leaf Numbers
// Difficulty: Medium
// Topic: DFS
// LeetCode URL: https://leetcode.com/problems/sum-root-to-leaf-numbers

// Approach:
// Use DFS to traverse all root-to-leaf paths while forming a number (`num`).
// At each node, update num = num * 10 + node->val.
// When a leaf node is reached, add num to the total sum.
// Pass num by value (separate path values) and sum by reference (accumulate result).

// Time Complexity: O(n)
// Space Complexity: O(h)

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
    void dfs(TreeNode* root, int& sum, int num) {
        if (root == NULL) {
            return;
        }

        num = (num * 10) + root->val;

        if (root->left == NULL && root->right == NULL) {
            sum += num;
            return;
        }

        dfs(root->left, sum, num);
        dfs(root->right, sum, num);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;

        dfs(root, sum, num);
        return sum;
    }
};