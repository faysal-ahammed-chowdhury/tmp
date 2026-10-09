#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 2e5 + 9, LOG = 20, B = 400;
vector<int> g[N];
int par[N][LOG], depth[N];
int timer, disc[N], finish[N], node_at_time[N + N];
bool vis[N];
int freq[N];
int a[N], comp[N];
ll ans[N], freqfreq[N];

struct query {
  int l, r, extra, k, id;
  bool operator < (const query &x) const {
    if (l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];

inline void add(int i) {
  int node = node_at_time[i];
  int comp_val = comp[node];
  int val = a[node];
  // cout << "add: " << i << ' ' << node << ' ' << val << vis[node] << '\n';
  if (!vis[node]) {
    freq[comp_val]++;
    freqfreq[freq[comp_val]] += val;
  }
  else {
    freqfreq[freq[comp_val]] -= val;
    freq[comp_val]--;
  }
  vis[node] ^= 1;
}

void dfs(int u, int p) {
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  disc[u] = ++timer;
  node_at_time[timer] = u;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = ++timer;
  node_at_time[timer] = u;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 1; i <= n; i++) {
    comp[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }

  dfs(1, 0);

  for (int i = 1; i <= q; i++) {
    int u, v; cin >> u >> v >> Q[i].k;
    if (disc[u] > disc[v]) swap(u, v);
    int lc = lca(u, v);
    if (lc != u) {
      Q[i].l = finish[u], Q[i].r = disc[v];
      Q[i].extra = disc[lc];
    }
    else {
      Q[i].l = disc[u], Q[i].r = disc[v];
      Q[i].extra = 0;
    }
    Q[i].id = i;
  }

  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r, k = Q[i].k;

    // cout << L << ' ' << R << '\n';
    if (R < l) {
      while (l > L) add(--l);
      while (l < L) add(l++);
      while (r < R) add(++r);
      while (r > R) add(r--);
    } else {
      while (r < R) add(++r);
      while (r > R) add(r--);
      while (l > L) add(--l);
      while (l < L) add(l++);
    }
    if (Q[i].extra) {
      // cout << Q[i].extra << '\n';
      add(Q[i].extra);
    }
    ans[Q[i].id] = freqfreq[k];
    if (Q[i].extra) add(Q[i].extra);
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

  return 0;
}