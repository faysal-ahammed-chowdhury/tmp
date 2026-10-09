#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

  int n, m1, m2; cin >> n >> m1 >> m2;
  DSU dsu1(n), dsu2(n);
  while (m1--) {
    int u, v; cin >> u >> v;
    dsu1.merge(u, v);
  }

  while (m2--) {
    int u, v; cin >> u >> v;
    dsu2.merge(u, v);
  }

  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!dsu1.same(i, j) and !dsu2.same(i, j)) {
        dsu1.merge(i, j);
        dsu2.merge(i, j);
        ans.push_back({i, j});
      }
    }
  }

  cout << ans.size() << '\n';
  for (auto [u, v] : ans) {
    cout << u << ' ' << v << '\n';
  }

  return 0;
}