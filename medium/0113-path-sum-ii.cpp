// Problem: Path Sum II
// Difficulty: Medium
// Topic: DFS
// LeetCode URL: https://leetcode.com/problems/path-sum-ii

// Approach:
// Use DFS with backtracking.
// Maintain current path and remaining sum.
// At each node:
//  - add node to path and subtract its value from sum.
//  - if it's a leaf and sum == 0 → store path.
//  - recurse left and right.
//  - backtrack by removing current node from path.

// Time Complexity: O(n)
// Space Complexity: O(H)  H is height.

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
    void dfs(TreeNode* root, vector<int>& path, int remaining,
             vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }

        remaining -= root->val;
        path.push_back(root->val);

        if (remaining == 0 && root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        }

        dfs(root->left, path, remaining, ans);
        dfs(root->right, path, remaining, ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, path, targetSum, ans);
        return ans;
    }
};