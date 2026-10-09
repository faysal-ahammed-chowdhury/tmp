#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int mx = 0;
  int mn = a[n];
  for (int i = n - 1; i >= 1; i--) {
    mx = max(mx, a[i] - mn);
    mn = min(mn, a[i]);
  }


  for (int i = 2; i <= n; i++) {
    if (a[i] >= a[i - 1]) continue;
    a[i] += mx;
  }

  if (is_sorted(a + 1, a + n + 1)) cout << "YES\n";
  else cout << "NO\n";
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