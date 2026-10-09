#include<bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

long long get_rand(long long l, long long r) {
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = get_rand(1, 2);
  cout << t << '\n';

  while (t--) {

    int n = get_rand(2, 8);
    int max_edges = n * (n - 1) / 2;

    int m = get_rand(n - 1, max_edges);

    cout << n << " " << m << '\n';

    set<pair<int, int>> edges;

    // Step 1: build random tree (ensures connected)
    for (int i = 2; i <= n; i++) {
      int p = get_rand(1, i - 1);

      int u = p;
      int v = i;

      edges.insert({min(u, v), max(u, v)});
    }

    // Step 2: add extra edges
    while ((int)edges.size() < m) {
      int u = get_rand(1, n);
      int v = get_rand(1, n);

      if (u == v) continue;

      auto e = make_pair(min(u, v), max(u, v));
      if (edges.count(e)) continue;

      edges.insert(e);
    }

    // Step 3: print edges with weights
    for (auto [u, v] : edges) {
      int w = get_rand(1, 20);
      cout << u << " " << v << " " << w << '\n';
    }
  }

  return 0;
}