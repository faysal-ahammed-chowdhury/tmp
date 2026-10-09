#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int mn = 2e9, mx = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (i & 1) mn = min(mn, x);
    else mx = max(mx, x);
  }

  if (n & 1) {
    cout << "NO\n";
    return;
  }

  if (mn <= mx + 1) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
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