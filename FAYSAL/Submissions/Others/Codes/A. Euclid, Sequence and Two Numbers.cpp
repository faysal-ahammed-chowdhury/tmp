#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  bool ok = true;
  for (int i = 1; i + 2 <= n; i++) {
    ok &= a[i + 2] == (a[i] % a[i + 1]);
  }

  if (ok) {
    cout << a[1] << ' ' << a[2] << '\n';
    return;
  }

  cout << -1 << '\n';
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