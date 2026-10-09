#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, x, y, z; cin >> n >> x >> y >> z;
  int tot = (x + y);

  int ans1 = (n + tot - 1) / tot;

  n -= z * x;

  int ans2 = z;
  tot = (x + (10 * y));
  ans2 += (n + tot - 1) / tot;

  cout << min(ans1, ans2) << '\n';
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