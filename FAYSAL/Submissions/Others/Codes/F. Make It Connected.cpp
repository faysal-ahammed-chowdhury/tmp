#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, m, a[N];
vector<array<int, 3>> edges;

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int mn = 1e18, node = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    if (mn == a[i]) {
      node = i;
    }
  }

  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (i == node) continue;
    edges.push_back({a[node] + a[i], i, node});
  }

  sort(edges.begin(), edges.end());

  DSU dsu(n);

  int ans = 0;
  for (auto [w, u, v] : edges) {
    if (dsu.same(u, v)) continue;

      dsu.merge(u, v);
      ans += w;
  }


  cout << ans << '\n';

  return 0;
}