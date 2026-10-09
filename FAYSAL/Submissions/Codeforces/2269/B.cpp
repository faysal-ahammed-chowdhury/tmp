#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int one = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 1) {
      one++;
      continue;
    }
    if (x == 4) {
      mp[0]++;
      continue;
    }
    for (int j = 1; j <= max(n, 100ll); j++) {
      string s = to_string(x);
      int y = 0;
      for (auto c : s) {
        int z = c - '0';
        y += z * z;
      }

      x = y;

      if (y == 1) {
        one++;
        break;
      }
      if (y == 4) {
        mp[j % 8]++;
        break;
      }
    }
    // cout << x << '\n';
  }

  int ans = (one * (one - 1)) / 2;
  for (auto [_, cnt] : mp) {
    ans += (cnt * (cnt - 1)) / 2;
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