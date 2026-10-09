#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int x = 1;
  set<int> se;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    while (se.find(x) != se.end()) {
      x++;
    }
    cout << x << ' ';
    se.insert(x);
    if (last != 0) {
      se.insert(last + x);
    }
    last = x;
  }
  cout << '\n';
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