#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int a, b; cin >> a >> b;
  int x = a, y = b;
  int ans1 = 0;
  int xf = 1;
  for (int i = 0; i <= 25; i++) {
    int here = (1ll << i);
    if (xf) {
      if (x >= here) {
        ans1 = i + 1;
        x -= here;
      }
      else break;
    }
    else {
      if (y >= here) {
        ans1 = i + 1;
        y -= here;
      }
      else break;
    }

    xf ^= 1;
  }

  x = a, y = b;
  int ans2 = 0;
  xf = 0;
  for (int i = 0; i <= 25; i++) {
    int here = (1ll << i);
    if (xf) {
      if (x >= here) {
        ans2 = i + 1;
        x -= here;
      }
      else break;
    }
    else {
      if (y >= here) {
        ans2 = i + 1;
        y -= here;
      }
      else break;
    }

    xf ^= 1;
  }

  cout << max(ans1, ans2) << '\n';
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