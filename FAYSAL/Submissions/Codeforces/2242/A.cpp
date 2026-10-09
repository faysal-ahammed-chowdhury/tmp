#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  bool ok = false;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x >= 3) ok = true;
    if (x == 2) cnt++;
  }

  if (cnt >= 2) ok = true;

  if (ok) cout << "YES\n";
  else cout << "NO\n";
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