#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt += a[i] == 0;
  }

  if (cnt <= 1) {
    cout << -1 << '\n';
    return;
  }

  int ans = 0;
  if (a[1] != 0) ans++;
  if (a[n] != 0) ans++;

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