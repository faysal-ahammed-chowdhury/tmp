#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }
void CLR(ll &N, int pos) { (N &= ~(1ll << pos)); }

void solve() {
  int x, y; cin >> x >> y;

  int ans = 0, op = 0;
  for (int k = 30; k >= 0; k--) {
    if (CHECK(x, k) == false and CHECK(y, k) == false) {
      int val = (1ll << k);
      int need = val - y;
      if (x >= need) {
        SET(ans, k);
        x -= need;
        y += need;
        op += need;
      }
    }
    else if (CHECK(x, k) != CHECK(y, k)) {
      SET(ans, k);
    }

    CLR(x, k);
    CLR(y, k);
  }

  cout << ans << ' ' << op << '\n';
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