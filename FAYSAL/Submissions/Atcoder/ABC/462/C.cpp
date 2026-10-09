#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);

  int mn = 1e9;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto [x, y] = a[i];
    if (y < mn) ans++;

    mn = min(mn, y);
  }

  cout << ans << '\n';

  return 0;
}