#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  int mx = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '#') {
      cnt++;
    }
    else {
      mx = max(mx, cnt);
      cnt = 0;
    }
  }
  mx = max(mx, cnt);

  cout << (mx + 1) / 2 << '\n';
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