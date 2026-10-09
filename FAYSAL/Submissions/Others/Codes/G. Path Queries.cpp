#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, m;
vector<array<int, 3>> edges;
vector<pair<int, int>> Q; 
ll ans[N];

void clr(int n) {
  edges.clear();
  Q.clear();
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
  cin >> n >> m;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  sort(edges.begin(), edges.end());

  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    Q.push_back({x, i});
  }

  sort(Q.begin(), Q.end());

  ll cur = 0;
  DSU dsu(n);
  int i = 0;
  for (auto [x, id] : Q) {
    for (; i < edges.size() and edges[i][0] <= x; i++) {
      auto [w, u, v] = edges[i];
      int sz1 = dsu.get_size(u);
      int sz2 = dsu.get_size(v);
      dsu.merge(u, v);
      int sz3 = dsu.get_size(v);

      cur -= (1ll * sz1 * (sz1 - 1)) / 2;
      cur -= (1ll * sz2 * (sz2 - 1)) / 2;
      cur += (1ll * sz3 * (sz3 - 1)) / 2;
    }

    ans[id] = cur;
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
