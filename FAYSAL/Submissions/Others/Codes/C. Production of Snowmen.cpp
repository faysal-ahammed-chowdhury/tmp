#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  int cnt1[n + 1];
  memset(cnt1, 0, sizeof cnt1);
  for (int j = 1; j <= n; j++) {
    bool ok = true;
    for (int i = 1, jj = j; i <= n; i++, jj++) {
      if (jj > n) jj = 1;
      ok &= b[jj] > a[i];
    }
    if (ok) cnt1[j]++;
  }

  int cnt2[n + 1];
  memset(cnt2, 0, sizeof cnt2);
  for (int j = 1; j <= n; j++) {
    bool ok = true;
    for (int k = 1, jj = j; k <= n; k++, jj++) {
      if (jj > n) jj = 1;
      ok &= b[jj] < c[k];
    }
    if (ok) cnt2[j]++;
  }

  int ans = 0;
  int sum1 = 0, sum2 = 0;
  for (int j = 1; j <= n; j++) {
    sum1 += cnt1[j];
    sum2 += cnt2[j];
  }

  for (int i = 1; i <= n; i++) {
    ans += sum1 * sum2;
  }

  // cout << sum2 << '\n';
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