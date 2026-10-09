#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

const int N = 2e5 + 9, LOG = 20;
const ll inf = 1e18;
vector<array<int, 2>> g[N];
vector<array<int, 3>> edges;
int par[N][LOG], tree_mx[N][LOG], depth[N];

void clr(int n) {
  edges.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear();
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

void dfs(int u, int p, int dis) {
  par[u][0] = p;
  tree_mx[u][0] = dis;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
    tree_mx[u][i] = max(tree_mx[u][i - 1], tree_mx[par[u][i - 1]][i - 1]); // change here
  }
  for (auto [v, w] : g[u]) {
    if (v != p) {
      dfs(v, u, w);
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

int dist(int u, int v) {
  int l = lca(u, v);
  return (depth[u] - depth[l]) + (depth[v] - depth[l]);
}

int query_max(int u, int v) {
  int l = lca(u, v);
  int d = dist(l, u);
  int ans = 0;
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = max(ans, tree_mx[u][i]);
      u = par[u][i];
    }
  }
  d = dist(l, v);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = max(ans, tree_mx[v][i]);
      v = par[v][i];
    }
  }
  return ans;
}

void solve() {
  int n, m, x; cin >> n >> m >> x;
  clr(n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  sort(edges.begin(), edges.end());

  DSU dsu(n);
  set<pair<int, int>> se;
  ll sum = 0;
  for (auto [w, u, v] : edges) {
    if (dsu.same(u, v) == false) {
      sum += w;
      se.insert({u, v});
      dsu.merge(u, v);
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
  }

  dfs(1, 0, 0);
  ll ans = inf;

  for (auto [w, u, v] : edges) {
    if (se.find({u, v}) != se.end()) {
      ll tmp = sum - w + (w ^ x);
      ans = min(ans, tmp);
    }
    else {
      ll tmp = sum + (w ^ x);
      tmp -= query_max(u, v);
      ans = min(ans, tmp);
      ans = min(ans, sum);
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}