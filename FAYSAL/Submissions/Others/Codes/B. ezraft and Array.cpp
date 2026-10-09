#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;

  if (n == 2) {
    cout << "-1\n";
    return;
  }

  if (n >= 1) cout << 2 << ' ';
  if (n >= 2) cout << 4 << ' ';
  if (n >= 3) cout << 6 << ' ';
  ll x = 6;
  for (int i = 4; i <= n; i++) {
    x *= 2;
    cout << x << ' ';
  }
  cout << '\n';
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