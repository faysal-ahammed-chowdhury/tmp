#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  vector<int> v({a, b, c});
  sort(v.begin(), v.end());

  a = v[0];
  b = v[1];
  c = v[2];

  if (a + b >= c) cout << "Yes\n";
  else cout << "No\n";
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