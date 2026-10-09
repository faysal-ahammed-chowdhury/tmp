#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 9;
vector<int> g[N];
int n, mod, disc[N], finish[N];
int timer, par[N];
int dp[N], dp_p[N];

void dfs(int u, int p) {
  par[u] = p;
  disc[u] = ++timer;
  dp[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u] = 1ll * dp[u] * ((dp[v] + 1) % mod) % mod;
    }
  }
  finish[u] = timer;
}

void dfs2(int u, int p) {
  vector<int> vec;
  for (auto v : g[u]) {
    if (v == p) continue;
    vec.push_back(dp[v] + 1);
  }

  vector<int> pref, suff;
  int sz = vec.size();
  for (int i = 0; i < sz; i++) {
    if (pref.empty()) pref.push_back(vec[i]);
    else pref.push_back(1ll * pref.back() * vec[i] % mod);
  }

  for (int i = sz - 1; i >= 0; i--) {
    if (suff.empty()) suff.push_back(vec[i]);
    else suff.push_back(1ll * suff.back() * vec[i] % mod);
  }
  reverse(suff.begin(), suff.end());

  int i = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    int l = disc[u], r = finish[u];
    int x = 1ll * ((i - 1 >= 0) ? pref[i - 1] : 1) * ((i + 1 < sz) ? suff[i + 1] : 1) % mod;
    dp_p[v] = 1ll * ((dp_p[u] + 1) % mod) * x % mod;
    dfs2(v, u);
    i++;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> mod;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  dfs2(1, 0);

  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      cout << dp[1] << '\n';
      continue;
    }
    int ans = 1ll * dp[i] * ((dp_p[i] + 1) % mod) % mod;
    cout << ans << '\n';
  }

  return 0;
}