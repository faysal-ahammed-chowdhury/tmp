#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = n;
  for (int i = 1; i <= n; i++) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] < a[i]) cnt1++;
      else if (a[j] > a[i]) cnt2++;
    }

    ans = min(ans, max(cnt1, cnt2));
  }

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