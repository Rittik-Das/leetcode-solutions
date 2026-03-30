// Problem: Word Search
// Difficulty: Medium
// Topic: DFS
// LeetCode URL: https://leetcode.com/problems/word-search

// Approach:
// Start from each cell matching word[0], then explore 4 directions.
// At each step, check bounds, visited, and character match.
// Mark cell as visited, recurse for next index.
// If found, return true; else backtrack (unmark).
// If no path works, return false.

// Time Complexity: O(m * n * 4^L)  ## m*n for starting points, and 4^L for DFS exploration (L = word length)
// Space Complexity: O(m * n) ## for visited matrix + recursion stack (worst case)

class Solution {
public:
    bool dfs(int i, int j, int m, int n, int index, vector<vector<char>>& board,
             string& word, vector<vector<bool>>& visited) {
        if (index == word.length()) {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
            board[i][j] != word[index]) {
            return false;
        }
        visited[i][j] = true;
        // bool top = dfs(i - 1, j, m, n, index + 1, board, word, visited);
        // bool bottom = dfs(i + 1, j, m, n, index + 1, board, word, visited);
        // bool left = dfs(i, j - 1, m, n, index + 1, board, word, visited);
        // bool right = dfs(i, j + 1, m, n, index + 1, board, word, visited);

        if (dfs(i - 1, j, m, n, index + 1, board, word, visited) ||
            dfs(i + 1, j, m, n, index + 1, board, word, visited) ||
            dfs(i, j - 1, m, n, index + 1, board, word, visited) ||
            dfs(i, j + 1, m, n, index + 1, board, word, visited)) {
            visited[i][j] = false;
            return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, m, n, 0, board, word, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};