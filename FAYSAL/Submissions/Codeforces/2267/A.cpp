#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; char c; cin >> n >> c;
  string s; cin >> s;
  s = '.' + s;
  int ans = 0;
  int l = 1, r = n;
  while (l < r) {
    if (s[l] == s[r]) {
      l++, r--;
      continue;
    }
    else if (s[l] == c or s[r] == c) ans++;
    else ans += 2;
    l++, r--;
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