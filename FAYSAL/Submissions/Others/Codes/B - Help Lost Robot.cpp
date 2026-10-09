#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int d = abs(x1 - x2) + abs(y1 - y2);
  
  
  if (x1 == x2) {
    if (y1 < y2) cout << "up\n";
    else cout << "down\n";
  }
  else if (y1 == y2) {
    if (x1 < x2) cout << "right\n";
    else cout << "left\n";
  }
  else cout << "sad\n";
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