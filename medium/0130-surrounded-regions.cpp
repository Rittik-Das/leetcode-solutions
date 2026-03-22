// Problem: Surrounded Regions
// Difficulty: Medium
// Topic: DFS, BFS (Here DFS algorithm is used)
// LeetCode URL: https://leetcode.com/problems/surrounded-regions

// Approach:
// DFS function is called in the boundary 'O's.
// The connected 'O's with the boundary ones are made visited.
// A loop is being executed through the grid
// If any non visited 'O' is present then it is made 'X' 

// Time Complexity: O(mn)
// Space Complexity: O(mn)  *Can be improved removing the color flag and pointing the safe 'O's with any symbol(eg. #)

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board,
             vector<vector<string>>& color) {

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' ||
            color[i][j] != "WHITE") {
            return;
        }

        color[i][j] = "GRAY";
        dfs(i - 1, j, m, n, board, color); // upper element
        dfs(i, j - 1, m, n, board, color); // left element
        dfs(i + 1, j, m, n, board, color); // bottom element
        dfs(i, j + 1, m, n, board, color); // right element
        color[i][j] = "BLACK";
    }

    void solve(vector<vector<char>>& board) {

        //  m is no of rows and n is no of columns
        int m = board.size();
        int n = board[0].size();

        vector<vector<string>> color(m, vector<string>(n, "WHITE")); // flag

        int i, j;

        for (j = 0; j < n; j++) {
            // top row, i is fixed i.e 0
            if (board[0][j] == 'O' && color[0][j] == "WHITE") {
                dfs(0, j, m, n, board, color);
            }
            // bottom row, i is fixed i.e. m-1
            if (board[m - 1][j] == 'O' && color[m - 1][j] == "WHITE") {
                dfs(m - 1, j, m, n, board, color);
            }
        }

        for (i = 0; i < m; i++) {
            // left column j is fixed i.e. 0
            if (board[i][0] == 'O' && color[i][0] == "WHITE") {
                dfs(i, 0, m, n, board, color);
            }
            // right column j is fixed i.e. n-1
            if (board[i][n - 1] == 'O' && color[i][n - 1] == "WHITE") {
                dfs(i, n - 1, m, n, board, color);
            }
        }

        // // top row
        // i = 0;
        // for (j = 0; j < n; j++) {
        //     if (board[i][j] == 'O' && color[i][j] == "WHITE") {
        //         dfs(i, j, m, n, board, color);
        //     }
        // }

        // // left column
        // j = 0;
        // for (i = 1; i < m; i++) {
        //     if (board[i][j] == 'O' && color[i][j] == "WHITE") {
        //         dfs(i, j, m, n, board, color);
        //     }
        // }

        // // bottom row
        // i = m - 1;
        // for (j = 1; j < n; j++) {
        //     if (board[i][j] == 'O' && color[i][j] == "WHITE") {
        //         dfs(i, j, m, n, board, color);
        //     }
        // }

        // // right column
        // j = n - 1;
        // for (i = 1; i < m - 1; i++) {
        //     if (board[i][j] == 'O' && color[i][j] == "WHITE") {
        //         dfs(i, j, m, n, board, color);
        //     }
        // }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == 'O' && color[i][j] == "WHITE") {
                    board[i][j] = 'X';
                }
            }
        }
    }
};