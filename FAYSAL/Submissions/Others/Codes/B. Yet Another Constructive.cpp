#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n, k, m; cin >> n >> k >> m;
  if (k > m) {
    cout << "NO\n";
    return;
  }

  int need = m - k;
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    if (i == 1) cout << 1 + need << ' ';
    else cout << 1 << ' ';
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