#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int pos = 1;
  set<int> se;
  se.insert(1);
  for (int i = 1; i <= n; i++) {
    if (s[pos] == 'L') pos--;
    else pos++;
    se.insert(pos);
  }

  cout << se.size() << '\n';
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