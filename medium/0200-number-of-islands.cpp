// Problem: Number of Islands
// Difficulty: Medium
// Topic: BFS, DFS (Here BFS algorithm is used)
// LeetCode URL: https://leetcode.com/problems/number-of-islands

// Approach:
// BFS function is called every element which is not visited.
// Every BFS call makes all its connected "1" visited i.e. considering the island.
// Each sucessful BFS call is increases the count of island number. 

// Time Complexity: O(mn)
// Space Complexity: O(mn)  *Can be improved using a boolean flag instead of color flag

class Solution {
public:
    void bfs(int i, int j, int m, int n, vector<vector<char>>& grid,
             queue<pair<int, int>>& q, vector<vector<string>>& color) {

        q.push({i, j});
        color[i][j] = "GRAY";

        while (!q.empty()) {

            pair<int, int> u = q.front();
            q.pop();

            int a = u.first;
            int b = u.second;

            if (b - 1 >= 0 && grid[a][b - 1] == '1' &&
                color[a][b - 1] == "WHITE") { // left node

                color[a][b - 1] = "GRAY";
                q.push({a, b - 1});
            }

            if (a + 1 < m && grid[a + 1][b] == '1' &&
                color[a + 1][b] == "WHITE") { // bottom node

                color[a + 1][b] = "GRAY";
                q.push({a + 1, b});
            }

            if (b + 1 < n && grid[a][b + 1] == '1' &&
                color[a][b + 1] == "WHITE") { // right node

                color[a][b + 1] = "GRAY";
                q.push({a, b + 1});
            }

            if (a - 1 >= 0 && grid[a - 1][b] == '1' &&
                color[a - 1][b] == "WHITE") { // top node

                color[a - 1][b] = "GRAY";
                q.push({a - 1, b});
            }

            color[a][b] = "BLACK";
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // m --> rows, n --> columns
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        int i, j;

        queue<pair<int, int>> q; // queue
        vector<vector<string>> color(m, vector<string>(n, "WHITE")); // flag

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '1' && color[i][j] == "WHITE") {
                    bfs(i, j, m, n, grid, q, color);
                    num++;
                }
            }
        }
        return num;
    }
};