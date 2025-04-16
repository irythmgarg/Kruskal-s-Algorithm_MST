# Kruskal-s-Algorithm_MST
# ⚙️ Minimum Spanning Tree using Kruskal’s Algorithm (with DSU) – C++

This repository contains an efficient implementation of **Kruskal's Algorithm** using **Disjoint Set Union (DSU)**
to compute the **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph.

---

## 📌 Problem Statement

Given a weighted, undirected graph represented by an adjacency list, compute the sum of weights of the **Minimum Spanning Tree** (MST) using **Kruskal’s algorithm**.

---

## 🚀 Algorithm Overview

Kruskal’s algorithm works by:
- Sorting all edges by weight (ascending).
- Iterating through edges and greedily selecting the ones that **don’t form a cycle**, using **Union-Find (DSU)** to detect cycles.
- Continuing until exactly **V-1 edges** are selected for a graph with **V vertices**.

---

## 🧾 Input Format

- `V`: Integer representing number of vertices in the graph.
- `adj`: Adjacency list where each entry `adj[i]` is a list of `{neighbor, weight}`.

---

## 📤 Output Format

- Returns a single integer: the **total weight of the MST**.

---

🧠 Concepts Used
Disjoint Set Union (DSU) / Union-Find with:
Path Compression (in find)
Union by Rank
Edge List Conversion from Adjacency List
Edge Sorting
Cycle Detection

📊 Time & Space Complexity
Time Complexity: O(E log E), where E is the number of edges (sorting step dominates).
Space Complexity: O(V + E)

📎 Notes
Always check if the number of edges in the MST is exactly V - 1 to ensure correctness.
Kruskal is ideal for sparse graphs, unlike Prim’s which can be faster for dense graphs.

## ✅ Example Usage

```cpp
int V = 4;
vector<vector<int>> adj[4];
adj[0].push_back({1, 1});
adj[1].push_back({0, 1});
adj[0].push_back({2, 3});
adj[2].push_back({0, 3});
adj[1].push_back({2, 1});
adj[2].push_back({1, 1});
adj[1].push_back({3, 4});
adj[3].push_back({1, 4});

Solution sol;
int mst_cost = sol.spanningTree(V, adj);
cout << "MST Cost: " << mst_cost << endl;


👨‍💻 Author
Your Name – @irythmgarg [Ridham Garg]
