# Competitive Programming Code Library

A structured collection of algorithms, data structures, mathematical routines, and problem solutions primarily targeted at competitive programming platforms (Codeforces, AtCoder, CSES, Spoj, UVA, CodeChef) implemented in C++ and Python.

---

## 📂 Repository Structure

The library is organized modularly by topic:

```text
codelibrary/
├── Bitwise/                # Bit tricks, manipulation patterns, and bitmask techniques
├── C++/
│   └── CodeForces Problems1/  # Contest submissions, templates, and stress-testing tools
├── DYNAMIC PROGRAMMING/    # Classical DP, memoization, digit/tree DP, knapsack variations
├── GRAPH/                  # Traversals (BFS/DFS), DSU, MST, Dijkstra, 2-SAT, Convex Hull
├── Math/                   # Number theory, combinatorics, matrix exponentiation, BigInt
├── RANGE QUERY/            # Segment Trees (Lazy), Sparse Table, Mo's Algorithm (Sqrt Dec.)
├── Recursion/              # Recursive back-tracking, permutation/subset generation
├── SEARCH AND SORT/        # Binary search paradigms, Two Pointers, Sliding Window, sorting
└── STRING/                 # KMP, Manacher's, String Hashing (Double Hashing)
```

---

## 🛠️ Key Topics & Implementations

### 1. Graphs & Trees
* **Traversal:** Single-source shortest path, BFS/DFS 2D directional grids, Bipartite verification.
* **Shortest Path:** Dijkstra (`std::priority_queue` & `std::set`), Floyd-Warshall, SPFA.
* **Trees & Spanning:** Kruskal's & Prim's algorithms, Disjoint Set Union (DSU) optimizations.
* **Advanced:** 2-SAT solver (`giantpizza`), Convex Hull algorithms.

### 2. Range Queries
* **Segment Trees:** Point update & range queries, lazy propagation.
* **Mo's Algorithm:** Sqrt decomposition and Hilbert curve ordering.
* **Static Range Queries:** Sparse Table for $O(1)$ Range Minimum Query (RMQ).

### 3. Mathematics & Number Theory
* Sieve of Eratosthenes, Miller-Rabin Primality, Pollard's Rho.
* Combinatorics: Catalan numbers, Burnside's Lemma, Derangements, Lucas' Theorem, $n\text{Cr} \pmod m$.
* Linear Diophantine equations and Matrix Exponentiation.

### 4. Bit Manipulation
* Subset generation via bitmasking.
* Constant-time bit hacks: finding/toggling $k$-th bit, counting set bits, isolating rightmost set bit.

---

## 🧪 Contest & Stress Testing Tools

Located inside `C++/CodeForces Problems1/`:

* `template.cpp`: Fast I/O template and utility macros for contest environments.
* `randomTestGenerator.cpp`: Generator script for randomized inputs.
* `a_bruteforce.cpp`: Verified brute-force solution used as an oracle.
* `checker.sh`: Bash script to stress test solutions against the oracle using generated random cases until an edge-case mismatch is discovered.

### Running the Stress Tester (Bash / WSL / Git Bash):
```bash
bash checker.sh
```

---

## 🚀 Compilation & Build Guidelines

To compile solutions locally using competitive programming warning flags and fast assertions:

```bash
g++ -O2 -std=c++17 -Wall -Wextra -Wshadow -DLOCAL solution.cpp -o solution
```

---

## 📄 License

This repository is maintained for educational reference and competitive programming preparation. Released under the [MIT License](LICENSE).