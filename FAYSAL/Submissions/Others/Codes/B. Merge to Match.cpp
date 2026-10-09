#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  if (m + m > n) {
    cout << "NO\n";
    return;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  bool ok = true;
  int en = n - m + 1;
  for (int i = 1; i <= m; i++, en++) {
    int st = i;
    // cout << st << ' ' << en << '\n';
    ok &= a[st] <= b[i];
    ok &= a[en] >= b[i];
  }

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