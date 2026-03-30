// Problem: Perfect Squares
// Difficulty: Medium
// Topic: BFS
// LeetCode URL: https://leetcode.com/problems/perfect-squares

// Approach:
// Take the value and subtract with all possible squares.
// Check the values if 0 then return level or height if not then subtract again.
// The checking will be done using bfs logic so that we move same distance to each possibility.

// Time Complexity: O(n*n^0.5)
// Space Complexity: O(n)

class Solution {
public:
    int numSquares(int n) {
        // int a = (int)sqrt(n);
        int i;

        queue<pair<int, int>> q;
        vector<bool> already_present(n + 1, false);
        q.push({n, 0});
        already_present[n] = true;

        while (!q.empty()) {
            pair<int, int> p;
            p = q.front();
            q.pop();
            int val = p.first;
            int level = p.second;
            level++;

            for (i = 1; i * i <= val; i++) {
                int curr_val;
                curr_val = val - (i * i);
                if (curr_val == 0) {
                    return level;
                }
                // else if (curr_val < 0) {
                //     break;
                // }
                else {
                    if (!already_present[curr_val]) {
                        q.push({curr_val, level});
                        already_present[curr_val] = true;
                    }
                }
            }
        }
        return -1;
    }
};