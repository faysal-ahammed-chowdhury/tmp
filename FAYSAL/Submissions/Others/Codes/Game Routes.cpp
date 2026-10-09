#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, mod = 1e9 + 7;
vector<int> g[N];
int n, m, indeg[N];
int ans[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    indeg[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> vec;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vec.push_back(u);
    for (auto v : g[u]) {
      indeg[v]--;
      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  reverse(vec.begin(), vec.end());

  ans[n] = 1;
  for (auto u : vec) {
    for (auto v : g[u]) {
      ans[u] += ans[v];
      ans[u] %= mod;
    }
  }

  cout << ans[1] << '\n';

  return 0;
}