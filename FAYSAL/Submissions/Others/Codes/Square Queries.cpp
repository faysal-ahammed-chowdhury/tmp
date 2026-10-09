#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, m;
int t[2005][2005], a[505][505];


// for build, we just call build_x(1, 0, n-1) from main;
// (0-based) memory 16 * m * n
// time per query, update - O(lg n * lg m);
void build_y(int vx, int lx, int rx, int
             vy, int ly, int ry) {
  if (ly == ry) {
    if (lx == rx) t[vx][vy] = a[lx][ly];
    else t[vx][vy] = max(t[vx * 2][vy],
                           t[vx * 2 + 1][vy]);
  } else {
    int my = (ly + ry) / 2;
    build_y(vx, lx, rx, vy * 2, ly, my);
    build_y(vx, lx, rx, vy * 2 + 1, my +
            1, ry);
    t[vx][vy] = max(t[vx][vy * 2], t[vx][vy
                                         * 2 + 1]);
  }
}
void build_x(int vx, int lx, int rx) {
  if (lx != rx) {
    int mx = (lx + rx) / 2;
    build_x(vx * 2, lx, mx);
    build_x(vx * 2 + 1, mx + 1, rx);
  }
  build_y(vx, lx, rx, 1, 0, m - 1);
}
int sum_y(int vx, int vy, int tly, int
          try_, int ly, int ry) {
  if (ly > ry) return 0;
  if (ly == tly && try_ == ry) return
      t[vx][vy];
  int tmy = (tly + try_) / 2;
  return max(sum_y(vx, vy * 2, tly, tmy, ly,
                   min(ry, tmy)), sum_y(vx, vy * 2 +
                                        1, tmy + 1, try_, max(ly, tmy +
                                            1), ry));
}
int sum_x(int vx, int tlx, int trx, int
          lx, int rx, int ly, int ry) {
  if (lx > rx) return 0;
  if (lx == tlx && trx == rx) return
      sum_y(vx, 1, 0, m - 1, ly, ry);
  int tmx = (tlx + trx) / 2;
  return max(sum_x(vx * 2, tlx, tmx, lx,
                   min(rx, tmx), ly, ry), sum_x(vx *
                       2 + 1, tmx + 1, trx, max(lx, tmx +
                           1), rx, ly, ry));
}

int cs;
void solve() {
  int q; cin >> n >> q;
  m = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  build_x(1, 0, n - 1);

  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int x1, y1, s; cin >> x1 >> y1 >> s;
    int x2 = x1 + s - 1;
    int y2 = y1 + s - 1;
    x1--;
    x2--;
    y1--;
    y2--;

    cout << sum_x(1, 0, n - 1, x1, x2, y1, y2) << '\n';
  }
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