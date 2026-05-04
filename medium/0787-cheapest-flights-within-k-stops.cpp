// Problem: Cheapest Flights Within K Stops
// Difficulty: Medium
// Topic: Shortest Path
// LeetCode URL: https://leetcode.com/problems/cheapest-flights-within-k-stops

// Approach:
// Use a modified Bellman-Ford algorithm where we relax all flights (edges) k+1 times
// (since at most k stops means at most k+1 edges), and in each iteration we use a
// temporary array to compute updated minimum costs from the previous state so that
// paths do not exceed the allowed number of edges, finally giving the cheapest cost
// to reach dst or -1 if it is not reachable within k stops.

// Time Complexity: O(k * E)
// Space Complexity: O(n)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = prices;

            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if (prices[u] == INT_MAX)
                    continue;

                if (temp[v] > prices[u] + cost) {
                    temp[v] = prices[u] + cost;
                }
            }
            prices = temp;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};