#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) cnt1++;
    else if (x % 4 == 0) cnt2++;
    else cnt3++;
  }

  cout << max({cnt1, cnt2, cnt3}) << '\n';
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