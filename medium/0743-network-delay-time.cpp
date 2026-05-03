// Problem: Network Delay Time
// Difficulty: Medium
// Topic: Shortest Path
// LeetCode URL: https://leetcode.com/problems/network-delay-time

// Approach:
// Represent the given input as a directed weighted graph using an adjacency list,
//    where each node stores its neighbors along with edge weights.
//
// Apply Dijkstra’s Algorithm starting from source node k to compute the
//    shortest time (distance) required to reach every node.
//
// Initialize a distance array with INT_MAX (infinity) and set dist[k] = 0.
//    Use a min-heap (priority queue) to always process the node with the
//    smallest current distance.
//
// For each node popped from the heap, skip it if it is an outdated entry
//    (i.e., if the stored distance is greater than the current known distance).
//
// For all adjacent nodes, perform relaxation:
//    if a shorter path is found via the current node, update the distance
//    and push the updated value into the priority queue.
//
// After Dijkstra completes, check if any node is still unreachable
//    (distance == INT_MAX). If yes, return -1.

// Otherwise, return the maximum value in the distance array,
//    which represents the time taken for the signal to reach all nodes.

// Time Complexity: O((V + E) log V)
// Space Complexity: O(V + E)

class Solution {
public:
    void relax(int u, int v, int w, vector<int>& dist) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
        }
    }

    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int s) {
        vector<int> dist(n + 1, INT_MAX);
        dist[s] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, s});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) {
                continue;
            }

            for (auto e : adj[u]) {
                int v = e.first, w = e.second;

                if (dist[v] > d + w) {
                    relax(u, v, w, dist);
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto t : times)
            adj[t[0]].push_back({t[1], t[2]});

        vector<int> dist = dijkstra(n, adj, k);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};