#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  ll xr = 0;
  for (int i = 1; i <= n; i++) {
    ll x; cin >> x;
    while (x % 2 == 0) x /= 2;
    x /= 2;
    xr ^= x;
  }

  if (xr) cout << "Alice\n";
  else cout << "Bob\n";
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