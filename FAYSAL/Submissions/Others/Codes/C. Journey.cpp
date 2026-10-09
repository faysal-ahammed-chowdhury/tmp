#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<int> g[N];
int n;

double dfs(int u, int p) {
  int child = g[u].size() - (u != 1);
  double ans = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    double len = 1 + dfs(v, u);
    ans += (1.0 / child) * (len);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  cout << fixed << setprecision(10);
  cout << dfs(1, 0) << '\n';

  return 0;
}