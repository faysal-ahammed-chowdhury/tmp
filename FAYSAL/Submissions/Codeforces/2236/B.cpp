#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  bool ok = true;
  for (int i = n; i > n - k; i--) {
    int cnt = 0;
    for (int j = i; j >= 1; j -= k) {
      if (s[j] == '1') cnt++;
    }

    ok &= cnt % 2 == 0;
  }

  if (ok) cout << "YES\n";
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