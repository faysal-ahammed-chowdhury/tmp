#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int cnt0 = 0, cnt1 = 0;
  for  (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 0) cnt0++;
    else cnt1++;
  }

  if (cnt0 <= cnt1) cout << "Bessie\n";
  else cout << "Elsie\n";
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