// Problem: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
// Difficulty: Hard
// Topic: MST
// LeetCode URL: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree

// Approach:
// Use Kruskal + DSU.
// Find original MST weight.
// For each edge:
// - Skip it → if MST weight increases or graph disconnects → critical.
// - Force add it → if MST weight stays same → pseudo-critical.
// skip = ignore edge.
// add = include edge first.

// Time Complexity: O(e log e + e * α(n))
// Space Complexity: O(n)

class Solution {
public:
    vector<int> parent, rank;

    void makeset(int x) {
        rank[x] = 0;
        parent[x] = x;
    }

    int findset(int x) {
        int root = x;

        while (root != parent[root]) {
            root = parent[root];
        }
        // We got the root....now all the intermediate elements are directly
        // connected with root

        while (x != root) {
            int previous = parent[x];
            parent[x] = root;
            x = previous;
        }

        return root;
    }

    void unionset(int x, int y) {
        int par_x = findset(x);
        int par_y = findset(y);

        if (par_x == par_y) {
            return;
        }

        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        } else if (rank[par_x] < rank[par_y]) {
            parent[par_x] = par_y;
        } else {
            parent[par_x] = par_y;
            rank[par_y]++;
        }
    }

    int kruskal(vector<vector<int>>& edges, int n, int skip, int add) {
        parent.resize(n);
        rank.resize(n);

        int i;
        for (i = 0; i < n; i++) {
            makeset(i);
        }

        int ans = 0;
        int edges_used = 0;

        // Default case
        if (skip == -1 && add == -1) {
            for (auto& e : edges) {
                int u = e[0];
                int v = e[1];
                int weight = e[2];

                if (findset(u) != findset(v)) {
                    unionset(u, v);
                    ans += weight;
                    edges_used++;
                }
            }
        }

        // Searching critical
        else if (add == -1) {
            int j;
            for (j = 0; j < edges.size(); j++) {
                if (j == skip) {
                    continue;
                }

                auto& e = edges[j];
                int u = e[0];
                int v = e[1];
                int weight = e[2];

                if (findset(u) != findset(v)) {
                    unionset(u, v);
                    ans += weight;
                    edges_used++;
                }
            }
        }

        // Searching pseudo-critical
        else if (skip == -1) {

            auto& e = edges[add];
            int u = e[0];
            int v = e[1];
            int weight = e[2];

            if (findset(u) != findset(v)) {
                unionset(u, v);
                ans += weight;
                edges_used++;
            }

            int j;
            for (j = 0; j < edges.size(); j++) {
                if (j == add) {
                    continue;
                }

                auto& e = edges[j];
                int u = e[0];
                int v = e[1];
                int weight = e[2];

                if (findset(u) != findset(v)) {
                    unionset(u, v);
                    ans += weight;
                    edges_used++;
                }
            }
        }

        if (edges_used != n - 1) {
            return INT_MAX;
        }
        
        return ans;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int i;
        for (i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2]; // sort by weight
             });

        int org_mst_val = kruskal(edges, n, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;

        for (i = 0; i < edges.size(); i++) {
            if (kruskal(edges, n, i, -1) > org_mst_val) {
                critical.push_back(edges[i][3]);
            } else if (kruskal(edges, n, -1, i) == org_mst_val) {
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        
        return {critical, pseudo_critical};
    }
};