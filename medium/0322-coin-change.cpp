// Problem: Coin Change
// Difficulty: Medium
// Topic: BFS
// LeetCode URL: https://leetcode.com/problems/coin-change

// Approach:
// Use BFS starting from the given amount.
// At each step, subtract each coin to get smaller values.
// Each BFS level represents number of coins used.
// Use a visited array to avoid recomputation.
// When we reach 0, return current level (minimum coins).
// If 0 is not reachable, return -1.

// Time Complexity: O(amount*n)
// Space Complexity: O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        queue<pair<int, int>> q;
        vector<bool> already_present(amount + 1, false);
        q.push({amount, 0});
        already_present[amount] = true;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int val = p.first;
            int level = p.second;

            for (auto x : coins) {
                int curr_val = val - x;
                if (curr_val == 0) {
                    return level + 1;
                } else if (curr_val > 0 && !already_present[curr_val]) {
                    already_present[curr_val] = true;
                    q.push({curr_val, level + 1});
                }
            }
        }
        return -1;
    }
};