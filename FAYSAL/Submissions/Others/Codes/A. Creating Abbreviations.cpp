#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  set<char> se;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    se.insert(char(s.front() - 32));
  }

  bool ok = true;
  for (int i = 1; i <= m; i++) {
    string s; cin >> s;
    for (auto c : s) {
      ok &= se.find(c) != se.end();
    }
    se.insert(s.front());
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