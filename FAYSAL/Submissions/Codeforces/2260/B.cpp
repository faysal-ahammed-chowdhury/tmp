#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int x, y, k; cin >> x >> y >> k;

  int ans = 0;
  while (y >= x * 2 and k > 0) {
    ans += (y % x);
    y++, x++;
    k--;
  }

  ans += k * (y % x);

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