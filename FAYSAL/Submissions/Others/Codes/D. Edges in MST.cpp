#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
map<int, vector<int>> g;
int timer, n, m;
set<int> vis;
map<int, int> disc, low;
map<pair<int, int>, int> bridges;
vector<array<int, 4>> edges;
int ans[N];

void bridges_dfs(int u, int p) { // find bridges
  disc[u] = low[u] = ++timer;
  vis.insert(u);
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis.find(v) != vis.end()) low[u] = min(low[u], disc[v]);
    else {
      bridges_dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] < low[v]) {
        bridges[(make_pair(min(u, v), max(u, v)))]++;
      }
    }
  }
}

struct DSU {
  vector<int> par, sz;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
    c = n;
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() { // number of connected components
    return c;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    return i;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, u, v, i});
  }

  sort(edges.begin(), edges.end());
  DSU dsu(n);

  for (int i = 0; i < m; i++) {
    // cout << "here: " << i << '\n';
    int j = i;
    vector<int> vec;
    map<pair<int, int>, int> mp;
    set<int> cancel;
    for (; j < m; j++) {
      if (edges[i][0] != edges[j][0]) break;
      auto [w, u, v, idx] = edges[j];
      u = dsu.find(u), v = dsu.find(v);
      if (u > v) swap(u, v);
      if (mp.find({u, v}) != mp.end()) {
        cancel.insert(mp[ {u, v}]);
        cancel.insert(idx);
      }
      else mp[ {u, v}] = idx;
      vec.push_back(u);
      g[u].push_back(v);
      g[v].push_back(u);
      // cout << u << ' ' << v << '\n';
    }

    for (auto u : vec) {
      if (vis.find(u) == vis.end()) {
        timer = 0;
        bridges_dfs(u, -1);
      }
    }

    set<int> se;
    for (auto [p, cnt] : bridges) {
      auto [u, v] = p;
      if (u > v) swap(u, v);
      if (cancel.find(mp[ {u, v}]) == cancel.end()) se.insert(mp[ {u, v}]);
    }

    g.clear();
    vis.clear();
    bridges.clear();
    low.clear();
    disc.clear();

    for (int k = i; k < j; k++) {
      auto [w, u, v, idx] = edges[k];
      if (!dsu.same(u, v)) {
        if (se.find(idx) != se.end()) ans[idx] = 2;
        else ans[idx] = 1;
      }
      else {
        ans[idx] = 0;
      }
    }

    for (int k = i; k < j; k++) {
      auto [w, u, v, idx] = edges[k];
      if (!dsu.same(u, v)) {
        dsu.merge(u, v);
      }
    }

    i = j - 1;
  }

  for (int i = 1; i <= m; i++) {
    if (ans[i] == 0) cout << "none\n";
    else if (ans[i] == 1) cout << "at least one\n";
    else cout << "any\n";
  }

  return 0;
}