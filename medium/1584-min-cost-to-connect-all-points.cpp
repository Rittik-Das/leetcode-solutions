// Problem: Min Cost to Connect All Points
// Difficulty: Medium
// Topic: MST
// LeetCode URL: https://leetcode.com/problems/min-cost-to-connect-all-points

// Approach:
// Treat each point as a node and build a complete graph using Manhattan distance.
// Use Prim’s Algorithm to find the Minimum Spanning Tree (MST).
// Maintain a key[] array where key[v] = minimum cost to connect node v to MST.
// Use a min-heap (priority_queue) to always pick the node with smallest key value.
// Start from node 0 (key = 0), and gradually include nodes into MST.
// For each selected node, update its neighbors if a cheaper connection is found.
// Use present_in_q[] to avoid processing a node more than once (due to duplicate heap entries).
// Accumulate the selected edge weights to get the final minimum cost.

// Time Complexity:
// Building adjacency list: O(n^2)
// Prim’s using min-heap: O(E log V) = O(n^2 log n)
// Overall: O(n^2 log n)

// Space Complexity:
// Adjacency list: O(n^2)
// Key, parent, visited arrays: O(n)
// Priority queue: O(n^2) (due to duplicates)
// Overall: O(n^2)

class Solution {
public:
    int prim(vector<vector<pair<int, int>>>& adj, int nop) {
        int ans = 0;
        vector<int> key(nop, INT_MAX);
        vector<int> parent(nop, -1);

        // vertices are 0 to nop-1. let's start with 0
        key[0] = 0;

        // a queue is reqd. to store the vertices along with the key value.
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        int i;
        for (i = 0; i < nop; i++) {
            q.push({key[i], i}); // {key, vertex}
        }

        // to check whether a vertex belongs to the q or not we will use an
        // array when any vertex will be poped out that will be false if not
        // false that means present in Q
        vector<bool> present_in_q(nop, true);

        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            int u = p.second;
            int wt = p.first;

            if (!present_in_q[u]) {
                continue;
            }

            present_in_q[u] = false;

            ans += wt;

            for (auto& edge : adj[u]) {
                int v = edge.second;
                if (present_in_q[v] && edge.first < key[v]) {
                    parent[v] = u;
                    key[v] = edge.first;
                    q.push({key[v], v});
                }
            }
        }
        return ans;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int nop = points.size();
        vector<vector<pair<int, int>>> adj(nop);

        int i, j;
        for (i = 0; i < nop; i++) {
            for (j = i + 1; j < nop; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({d, j});
                adj[j].push_back({d, i});
            }
        }
        return prim(adj, nop);
    }
};