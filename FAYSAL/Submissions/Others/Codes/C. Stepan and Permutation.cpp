#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, x, y; cin >> n >> x >> y;
  int a[n + 1];
  int idx[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }

  int d = __gcd(x, y);
  for (int i = 1; i <= n; i++) {
    int x = (idx[i] % d);
    if (x != (i % d)) {
      cout << "NO\n";
      return;
    }
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