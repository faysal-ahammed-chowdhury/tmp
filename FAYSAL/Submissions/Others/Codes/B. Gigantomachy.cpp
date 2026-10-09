#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1];

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  int cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    if (i == n) {
      cnt1 += a[i];
    }
    else {
      int nxt = a[i + 1] - 1;
      cnt1 += a[i] - nxt;
    }
  }

  int cnt2 = 0;
  for (int i = 1; i <= m; i++) {
    if (i == m) {
      cnt2 += b[i];
    }
    else {
      int nxt = b[i + 1] - 1;
      cnt2 += b[i] - nxt;
    }
  }

  // cout << (cnt1 <= cnt2) << '\n';

  if (cnt1 >= cnt2) cout << 1 << '\n';
  else cout << 2 << '\n';
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