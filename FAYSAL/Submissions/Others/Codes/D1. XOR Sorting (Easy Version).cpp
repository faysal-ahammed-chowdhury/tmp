#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 2e9;

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (is_sorted(a + 1, a + n + 1)) {
    cout << 0 << '\n';
    return;
  }

  for (int x = 1; x <= n; x *= 2) {
    int len = x * 2;
    int mn = inf, mx = 0;
    int old_mx = 0;
    bool ok = true;
    bool last = false;
    for (int i = 1; i <= n; i++) {
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
      last = false;
      if (i % len == 0) {
        last = true;
        if (old_mx > mn) {
          ok = false;
          break;
        }
        old_mx = mx;
        mn = inf, mx = 0;
      }
    }
    if (ok == false) continue;
    if (old_mx > mn and last == false) continue;

    cout << x << '\n';
    return;
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