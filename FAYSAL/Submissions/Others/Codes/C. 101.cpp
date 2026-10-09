#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int last = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == -1) last = i;
  }

  int last_one = -1;
  int cur = 0;
  int st = -1;
  for (int i = n; i >= 1; i--) {
    if (a[i] != 0) {
      if (last_one == -1) {
        if (last != -1) {
          if (last - i + 1 >= cur) {
            cur = last - i + 1;
            st = i;
          }
        }
      }
      else {
        if (last_one - i + 1 >= cur) {
          cur = last_one - i + 1;
          st = i;
        }
      }
    }

    if (a[i] == 1) last_one = i;
  }

  int en = st + cur - 1;

  for (int i = 1; i <= n; i++) {
    if (i == st or i == en) cout << 1 << ' ';
    else if (i > st and i < en) cout << 0 << ' ';
    else cout << max(0, a[i]) << ' ';
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