#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);

  int dp[35];
  memset(dp, -1, sizeof dp);

  while (q--) {
    int x; cin >> x;
    if (x > 32) {
      cout << 0 << '\n';
      continue;
    }
    int &ans = dp[x];
    if (ans != -1) {
      cout << ans << '\n';
      continue;
    }

    bool first = true;
    while (x--) {
      vector<int> v;
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          if (first) v.push_back(a[i] ^ a[j]);
            else v.push_back(b[i] ^ b[j]);
        }
      }
      first = false;
      sort(v.begin(), v.end());

      for (int i = 1; i <= n; i++) {
        b[i] = v[i - 1];
      }
    }

    ans = first ? a[n] - a[1] : b[n] - b[1];

    cout << ans << '\n';
  }
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