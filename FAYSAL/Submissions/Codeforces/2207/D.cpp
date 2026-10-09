#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 5e5 + 9, inf = 1e18;
vector<int> g[N];
int n, k, root;
int dp[N];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  vector<int> vec;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    vec.push_back(dp[v] + 1);
  }
  sort(vec.begin(), vec.end());
  if (vec.size() == 0) dp[u] = 0;
  else if (vec.size() == 1) dp[u] = vec[0];
  else {
    dp[u] = (vec[0] + vec[1] <= k + 1) ? 0 : vec[0];
  }
}

void solve() {
  cin >> n >> k >> root;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(root, 0);

  if (dp[root] == 0) cout << "YES\n";
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