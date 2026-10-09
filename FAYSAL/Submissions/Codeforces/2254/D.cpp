#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  int ans[n + 1], ans2[n + 1];
  a[0].first = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a + 1, a + n + 1);
  if (a[1].first != 0) {
    cout << -1 << '\n';
    return;
  }

  int cnt = 1;
  int sum = 0;
  int last = 0;

  int prev = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].first == a[i - 1].first) {
      cnt++;
      // cout << i << ' ' << cnt << '\n';
    }
    else {
      if (i == 1) {
        cnt = 1;
        continue;
      }
      if ((a[i].first - sum) % cnt != 0) {
        cout << -1 << '\n';
        return;
      }
      int x = (a[i].first - sum) / cnt;

      if (x <= prev) {
        cout << -1 << '\n';
        return;
      }

      prev = x;

      sum += x * cnt;
      cnt = 1;

      for (int j = last + 1; j < i; j++) {
        ans[j] = x;
        last = j;
      }
    }
  }

  for (int j = last + 1; j <= n; j++) {
    ans[j] = 1e18;
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    ans2[a[i].second] = ans[i];
    if (ans[i] < 1e18) mx = max(mx, ans[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (ans2[i] == 1e18) ans2[i] = mx + 1;
    cout << ans2[i] << ' ';
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