#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, K = 20;
int n, a[N];
vector<int> g[N];
int timer, disc[N], finish[N];
int subtree_gcd[N];
int val[N], tree[N][K];
int par[N];

void clr(int n) {
  timer = 0;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = val[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = __gcd(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); 
    }
  }
}

int query(int l, int r) {
  if (l > r) return 0;
  int k = log2_floor(r - l + 1);
  return __gcd(tree[l][k], tree[r - (1 << k) + 1][k]); 
}

void dfs(int u, int p) {
  disc[u] = ++timer;
  par[u] = p;
  subtree_gcd[u] = a[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    subtree_gcd[u] = __gcd(subtree_gcd[u], subtree_gcd[v]);
  }
  finish[u] = timer;
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

  for (int i = 1; i <= n; i++) {
    val[disc[i]] = a[i];
  }

  build(n);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll val = query(disc[1], disc[i] - 1);
    val = __gcd(val, 1ll * query(finish[i] + 1, n));
    for (auto v : g[i]) {
      if (v == par[i]) continue;
      val += subtree_gcd[v];
    }
    ans = max(ans, val);
    // cout << i << ' ' << val << '\n';
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