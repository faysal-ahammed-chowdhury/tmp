#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int a, b, x; cin >> a >> b >> x;
  if (a > b) swap(a, b);

  int cur = 0;
  while ((b / x) >= a) {
    b /= x;
    cur++;
  }

  if (a == b) {
    cout << cur << '\n';
    return;
  }

  int ans = 1e9;
  while (true) {
    if (a == b) break;

    ans = min(ans, cur + abs(a - b));

    if (b > 0) {
      b /= x;
      cur++;
    }

    ans = min(ans, cur + abs(a - b));
    
    if (a > 0) {
      a /= x;
      cur++;
    }
  }

  cout << min(ans, cur) << '\n';
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