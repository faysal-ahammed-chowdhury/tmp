#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(a[i]);
  }

  int mx = *max_element(a + 1, a + n + 1);
  se.erase(mx);
  int mex = mx == 0 ? 1 : 0;
  ll ans = mx + mex;

  for (int i = 2; i <= n; i++) {
    ans += mx;
    if (se.find(mex) != se.end() or mex == mx) {
      se.erase(mex);
      mex++;
      if (mex == mx) mex++;
    }
    ans += mex;
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