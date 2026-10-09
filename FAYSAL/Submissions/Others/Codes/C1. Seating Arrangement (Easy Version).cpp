#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, t, seat; cin >> n >> t >> seat;
  string s; cin >> s;
  s = '.' + s;

  int tables[t + 1];
  memset(tables, 0, sizeof tables);

  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'I') {
      for (int j = 1; j <= t; j++) {
        if (tables[j] == 0) {
          ans++;
          tables[j]++;
          break;
        }
      }
    }
    else if (s[i] == 'E') {
      bool done = false;
      for (int j = 1; j <= t; j++) {
        if (tables[j] > 0 and tables[j] < seat) {
          done = true;
          ans++;
          tables[j]++;
          break;
        }
      }

      if (done or cnt <= 0) continue;

      for (int j = 1; j <= t; j++) {
        if (tables[j] == 0 and cnt > 0) {
          ans++;
          tables[j]++;
          cnt--;
          break;
        }
      }
    }
    else {
      for (int j = 1; j <= t; j++) {
        if (tables[j] < seat) {
          if (tables[j] > 0) cnt++;
          ans++;
          tables[j]++;
          break;
        }
      }
    }
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