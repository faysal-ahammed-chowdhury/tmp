#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 1e5 + 9, MAX = 1e6 + 9, B = 400, LOG = 20, mod = 1e9 + 7;
vector<int> g[N];
int n, a[N], disc[N], finish[N];
int timer;
int node_at_time[N + N];
bool status[N];
int ans[N];
int par[N][LOG], depth[N];
int spf[MAX];
gp_hash_table<int, int, custom_hash> pf[MAX], mp;
int inv[N * 20];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int inverse(int x) {
  return power(x, mod - 2, mod);
}

int tmp;
void clr(int n) {
  mp.clear();
  timer = 0;
  tmp = 1;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    status[i] = false;
  }
}

void spf_sieve() {
  for (int i = 2; i < MAX; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MAX; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MAX; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void prec() {
  for (int i = 2; i < MAX; i++) {
    int x = i;
    while (x > 1) {
      int p = spf[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      pf[i][p] = pw;
    }
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= 20; j++) {
      int x = i * j;
      inv[x] = inverse(x);
    }
  }
}

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

inline void add_rem(int i) {
  int node = node_at_time[i];
  int val = a[node];
  if (!status[node]) {
    for (auto [p, pw] : pf[val]) {
      tmp = 1ll * tmp * inv[mp[p] + 1] % mod;
      mp[p] += pw;
      tmp = 1ll * tmp * (mp[p] + 1) % mod;
    }
  }
  else {
    for (auto [p, pw] : pf[val]) {
      tmp = 1ll * tmp * inv[mp[p] + 1] % mod;
      mp[p] -= pw;
      tmp = 1ll * tmp * (mp[p] + 1) % mod;
    }
  }
  status[node] ^= 1;
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dfs(1, 0);

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
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}