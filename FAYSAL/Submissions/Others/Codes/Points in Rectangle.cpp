#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree2D {
  vector<vector<int>> bit;
  int n, m;

  FenwickTree2D(int n, int m) {
    this->n = n;
    this->m = m;
    bit.resize(n);
    for (int i = 0; i < n; i++) {
      bit[i].assign(m, 0);
    }
  }

  int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
      for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
        ret += bit[i][j];
    return ret;
  }

  void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
      for (int j = y; j < m; j = j | (j + 1))
        bit[i][j] += delta;
  }
};

int cs;
void solve() {
  int q; cin >> q;
  FenwickTree2D ft(1005, 1005);

  bool vis[1005][1005];
  memset(vis, false, sizeof vis);
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int type; cin >> type;
    if (type == 0) {
      int x, y; cin >> x >> y;
      if (vis[x][y]) continue;
      vis[x][y] = true;
      ft.add(x, y, 1);
    }
    else {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      int ans = ft.sum(x2, y2);
      ans -= ft.sum(x1 - 1, y2);
      ans -= ft.sum(x2, y1 - 1);
      ans += ft.sum(x1 - 1, y1 - 1);

      cout << ans << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}