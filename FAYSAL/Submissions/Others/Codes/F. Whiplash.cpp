#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    xr ^= a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    xr ^= b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    ok &= a[i] == b[i];
  }

  if (ok) {
    cout << "YES\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    ok |= a[i] == xr;
  }

  if (!ok) {
    cout << "NO\n";
    return;
  }

  // cout << xr << '\n';

  vector<int> v;
  bool first = true;
  for (int i = 1; i <= n; i++) {
    if (a[i] == xr and first) {
      v.push_back(xr);
      first = false;
      continue;
    }

    v.push_back(a[i] ^ xr);
  }

  sort(v.begin(), v.end());

  ok = true;
  for (int i = 1; i <= n; i++) {
    // cout << b[i] << ' ' << v[i - 1] << '\n';
    ok &= b[i] == v[i - 1];
  }

  if (ok) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
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