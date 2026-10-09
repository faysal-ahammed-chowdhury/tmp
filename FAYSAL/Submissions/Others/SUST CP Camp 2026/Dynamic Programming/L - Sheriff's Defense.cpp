#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
int n, c, a[N];
ll dp[N][2];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = a[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += max(dp[v][0], dp[v][1] - (2ll * c));
  }
}

void solve() {
  cin >> n >> c;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  ll ans = max(dp[1][0], dp[1][1]);
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