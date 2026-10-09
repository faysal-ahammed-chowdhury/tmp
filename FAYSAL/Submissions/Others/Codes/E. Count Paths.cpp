#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
vector<int> g[N];
int n, col[N], par[N];
map<int, int> mp[N];
int ans;

void clr(int n) {
  ans = 0;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    par[i] = i;
    mp[i].clear();
  }
}

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (mp[u].size() > mp[v].size()) swap(u, v);
  for (auto [c, cnt] : mp[u]) {
    ans += mp[v][c] * cnt;
  }
  for (auto [c, cnt] : mp[u]) {
    mp[v][c] += cnt;
  }
  mp[u].clear();
  par[u] = v;
}

void dfs(int u, int p) {
  mp[u][col[u]] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
      // if (u == 1) {
      //   cout << "here: " << v << '\n';
      //   for (auto [c, cnt] : mp[find(u)]) {
      //     cout << c << ' ' << cnt << '\n';
      //   }
      // }
      mp[find(u)][col[u]] = 1;
    }
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) cin >> col[i];
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
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