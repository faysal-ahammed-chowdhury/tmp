#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all &= a[i] == 1;
  }
  if (all) {
    cout << 1 << '\n';
    return;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) continue;
    ans += a[i];
  }

  if (a[n] == 1) ans++;

  cout << ans << '\n';
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