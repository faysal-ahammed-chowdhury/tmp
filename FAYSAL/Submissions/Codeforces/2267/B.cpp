#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int freq[101];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  vector<int> ans;
  while (true) {
    int mx = 0, cnt = 0;
    for (int x = 100; x >= 1; x--) {
      if (freq[x]) {
        mx = x;
        cnt = freq[x];
        freq[x] = 0;
        for (int j = 1; j <= cnt; j++) {
          ans.push_back(x);
        }
        break;
      }
    }

    if (cnt == 0) break;

    for (int x = mx - 1; x >= 1; x--) {
      int c = min(freq[x], cnt);
      freq[x] -= c;
      for (int j = 1; j <= c; j++) {
        ans.push_back(x);
      }
    }
  }

  for (auto x : ans) {
    cout << x << ' ';
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