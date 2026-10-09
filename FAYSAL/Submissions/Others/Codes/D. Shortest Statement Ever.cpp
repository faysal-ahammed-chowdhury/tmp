#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

const int inf = 1e18;

pair<int, int> f(int x, int y) {
  bool flag = false;
  int p = x, q = 0;
  for (int k = 30; k >= 0; k--) {
    if (flag) {
      if (CHECK(x, k) == false) {
        SET(q, k);
      }
      continue;
    }
    if (CHECK(y, k)) {
      if (CHECK(x, k)) {
        flag = true;
        continue;
      }
      SET(q, k);
    }
  }

  flag = false;
  int qq = 0;
  int msb = 0;
  for (int k = msb; k <= 30; k++) {
    if (CHECK(x, k) == false) {
      int tmp = 1ll << k;
      for (int kk = k + 1; kk <= 30; kk++) {
        if (CHECK(y, kk) and !CHECK(p, kk)) {
          SET(tmp, kk);
        }
      }
      if (abs(qq - y) >= abs(tmp - y)) {
        qq = tmp;
        flag = true;
      }
    }
  }

  if (!flag) return {abs(q - y), q};

  return (abs(q - y) <= abs(qq - y)) ? make_pair(abs(q - y), q) : make_pair(abs(qq - y), qq);
}

void solve() {
  int x, y; cin >> x >> y;
  int xx = x, yy = y;
  auto [val1, q] = f(xx, yy);
  swap(xx, yy);
  auto [val2, p] = f(xx, yy);

  if (val1 <= val2) p = x;
  else q = y;

  cout << p << ' ' << q << '\n';
  // cout << abs(x - p) + abs(y - q) << '\n';
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