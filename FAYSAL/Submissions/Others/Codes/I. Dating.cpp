#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

const int N = 1e5 + 9, B = 400, LOG = 20;
vector<int> g[N];
int n, a[N], disc[N], finish[N];
int timer;
bool gender[N];
int node_at_time[N + N];
bool status[N];
int freq1[N], freq2[N];
int ans[N];
int par[N][LOG], depth[N];

void dfs(int u, int p) {
  disc[u] = ++timer;
  node_at_time[timer] = u;
  par[u][0] = p;
  depth[u] = depth[p] + 1;
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

struct query {
  int l, r, lc, id;
  bool operator < (const query &x) const {
    if (l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];

ll tmp;
inline void add_rem(int i) {
  int node = node_at_time[i];
  int val = a[node];
  // cout << status[node] << '\n';
  if (!status[node]) {
    if (gender[node]) {
      tmp += freq1[val];
      freq2[val]++;
    }
    else {
      tmp += freq2[val];
      freq1[val]++;
    }
  }
  else {
    if (gender[node]) {
      tmp -= freq1[val];
      freq2[val]--;
    }
    else {
      tmp -= freq2[val];
      freq1[val]--;
    }
  }
  status[node] ^= 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> gender[i];
  }
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

  dfs(1, 0);

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }

  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v; cin >> u >> v;
    if (disc[u] > disc[v]) swap(u, v);
    int lc = lca(u, v);
    if (lc == u) {
      Q[i].l = disc[u];
      Q[i].r = disc[v];
      Q[i].lc = -1;
    }
    else {
      Q[i].l = finish[u];
      Q[i].r = disc[v];
      Q[i].lc = lc;
    }
    Q[i].id = i;
  }
  
  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r;
    // cout << L << ' ' << R << ' ' << Q[i].lc << '\n';
    if (R < l) {
      while (l > L) add_rem(--l);
      while (l < L) add_rem(l++);
      while (r < R) add_rem(++r);
      while (r > R) add_rem(r--);
    } else {
      while (r < R) add_rem(++r);
      while (r > R) add_rem(r--);
      while (l > L) add_rem(--l);
      while (l < L) add_rem(l++);
    }
    if (Q[i].lc != -1) add_rem(disc[Q[i].lc]);
    ans[Q[i].id] = tmp;
    if (Q[i].lc != -1) add_rem(disc[Q[i].lc]);
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

  return 0;
}