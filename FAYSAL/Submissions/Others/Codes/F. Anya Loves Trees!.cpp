#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 1e9;
int n, a[N];
vector<int> g[N];
int leaf_cnt[N];
int mn[N], mx[N];
bool ok;

void clr(int n) {
  ok = true;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    mn[i] = inf;
    mx[i] = -inf;
    leaf_cnt[i] = 0;
  }
}

void dfs(int u, int p) {
  leaf_cnt[u] = 0;
  bool leaf = true;

  int cnt = 0, last = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    leaf = false;
    leaf_cnt[u] += leaf_cnt[v];
    mn[u] = min(mn[u], mn[v]);
    mx[u] = max(mx[u], mx[v]);
    if (mn[v] != last + 1 and last != 0) cnt++;
    last = mx[v];
  }

  if (leaf) {
    leaf_cnt[u] = 1;
    mn[u] = a[u];
    mx[u] = a[u];
  }
  int d = mx[u] - mn[u] + 1;
  // cout << u << ' ' << d << ' ' << leaf_cnt[u] << '\n';
  ok &= cnt <= 1;
  ok &= d == leaf_cnt[u];
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[p].push_back(i);
    g[i].push_back(p);
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ok = true;
  dfs(1, 0);

  if (ok) cout << "YES\n";
  else cout << "NO\n";
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