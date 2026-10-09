#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5 + 9;
int n, depth[N], ans[N];
vector<int> g[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    ans[i] = 0;
    depth[i] = 0;
    g[i].clear();
  }
}

void dfs(int u, int p) {
  ans[u] = 1;
  depth[u] = 0;
  vector<int> vec;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    depth[u] = max(depth[u], depth[v] + 1);
    vec.push_back(depth[v] + 1);
    ans[u] += ans[v];
  }

  if (vec.size() > 1) {
    sort(vec.rbegin(), vec.rend());
    ans[u] += vec[1];
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }

  dfs(1, 0);
  cout << ans[1] << '\n';
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