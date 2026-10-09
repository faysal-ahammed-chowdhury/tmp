#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  n += n;
  string ans(n + 1, '0');
  for (int i = 1; i <= n; i++) {
    int nxt = (i + 1) % n;
    if (nxt == 0) nxt = n;

    if (s[nxt] == '0' and s[i] == '1') ans[nxt] = '1';
    else if (s[i] == '1') ans[i] = '1';
  }

  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) ans1 += ans[i] == '1';
    else ans2 += ans[i] == '1';
  }

  cout << ans2 << ' ' << ans1 << '\n';
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