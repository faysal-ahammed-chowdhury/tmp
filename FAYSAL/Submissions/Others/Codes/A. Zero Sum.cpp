#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    cnt += x;
  }

  cnt = abs(cnt);

  if (cnt & 1) {
    cout << "NO\n";
    return;
  }
  
  cnt = abs(cnt / 2);

  if (cnt % 2 == 0) cout << "YES\n";
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