#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int cnt = 0;
  for (int i = 1; i + 3 <= n; i++) {
    string tmp = s.substr(i, 4);
    if (tmp == "2025") cnt++;
    else if (tmp == "2026") {
      cout << "0\n";
      return;
    }
  }

  if (cnt) cout << "1\n";
  else cout << "0\n";
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