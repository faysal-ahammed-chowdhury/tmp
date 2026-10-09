#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  set<int> se;
  se.insert(a);
  se.insert(b);
  se.insert(c);

  int ans = 0;
  while (se.size() == 3) {
    ans++;
    int mx = *(--se.end());
    int mn = *(se.begin());
    se.erase(mx);
    se.erase(mn);
    mn++;
    mx--;
    se.insert(mx);
    se.insert(mn);
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