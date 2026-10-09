#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  for (int i = 2; i < n; i++) {
    if (s[i - 1] == '1' and s[i + 1] == '1') s[i] = '1';
  }

  int mn = 0, mx = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    mx += s[i] == '1';
    if (s[i] == '1') cnt++;
    else {
      mn += cnt - ((cnt - 1) / 2);
      cnt = 0;
    }
  }
  mn += cnt - ((cnt - 1) / 2);

  cout << mn << ' ' << mx << '\n';
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