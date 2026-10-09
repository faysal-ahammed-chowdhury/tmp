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

  bool ok1[n + 1];
  memset(ok1, false, sizeof ok1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    x += (a[i] == 1 ? 1 : -1);
    if (x >= 0) ok1[i] = true;
  }

  int mn = 1e9;
  x = 0;
  for (int i = 1; i < n; i++) {
    x += (a[i] <= 2 ? 1 : -1);
    if (x - mn >= 0) {
      cout << "YES\n";
      return;
    }
    if (ok1[i]) mn = min(mn, x);
  }

  cout << "NO\n";
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