#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, m;
vector<array<int, 4>> edges;

void clr(int n) {
  edges.clear();
}

struct DSU {
  vector<int> par, sz;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
    c = n;
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() { // number of connected components
    return c;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    return i;
  }
};

void solve() {
  int k; cin >> n >> m >> k;
  clr(n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    int d = 0;
    if (w > k) {
      d = w - k;
      w = k;
    }
    edges.push_back({w, d, u, v});
  }

  sort(edges.begin(), edges.end());

  ll ans = 0;
  int mx = 0;
  DSU dsu(n);
  set<pair<int, int>> se;
  for (auto [w, d, u, v] : edges) {
    if (dsu.same(u, v)) continue;
    ans += d;
    mx = max(mx, w);
    dsu.merge(u, v);

    se.insert({u, v});
  }

  if (mx < k) {
    ll tmp = ans;
    ll cur = tmp + (k - mx);
    ans = cur;
    for (auto [w, d, u, v] : edges) {
      if (se.find({u, v}) != se.end()) continue;
      int cost = (w >= k) ? d : k - w;
      ll cur = tmp + (cost);
      ans = min(ans, cur);
    }
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