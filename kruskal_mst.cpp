#include <vector>
#include <algorithm>
using namespace std;

/**
 * Class to compute the Minimum Spanning Tree (MST) using Kruskal's Algorithm
 * with Disjoint Set Union (DSU) data structure.
 */
class Solution {
public:
    // Disjoint Set Union (Union-Find) support arrays
    vector<int> parent;
    vector<int> rank;

    /**
     * DSU: Find the root (ultimate parent) of a node with path compression
     */
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    /**
     * DSU: Union two sets by rank to keep tree shallow
     */
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    /**
     * Kruskal's Algorithm core: Accepts sorted edge list and constructs MST.
     */
    int Kruskal(vector<vector<int>> &vec) {
        int sum = 0;

        for (auto &temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            // If nodes are in different sets, include edge and merge sets
            if (find(u) != find(v)) {
                Union(u, v);
                sum += wt;
            }
        }

        // Note: Always check edge count == V-1 to ensure it's a valid MST

        return sum;
    }

    /**
     * Main function to build graph edges and apply Kruskal's Algorithm.
     *
     * @param V    Number of vertices
     * @param adj  Adjacency list where adj[i] = list of {neighbor, weight}
     * @return     Total weight of the Minimum Spanning Tree
     */
    int spanningTree(int V, vector<vector<int>> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);
        
        // Initialize each node's parent to itself
        for (int i = 0; i < V; i++)
            parent[i] = i;

        vector<vector<int>> vec; // Edge list: {u, v, weight}

        // Convert adjacency list to edge list
        for (int i = 0; i < V; i++) {
            for (auto &temp : adj[i]) {
                int u = i;
                int v = temp[0];
                int d = temp[1];
                vec.push_back({u, v, d});
            }
        }

        // Sort edges based on weight (ascending)
        sort(begin(vec), end(vec), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        return Kruskal(vec);
    }
};
