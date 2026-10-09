#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int mx = 0, mn = 7;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
  }

  cout << mx - mn + 1 << '\n';
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