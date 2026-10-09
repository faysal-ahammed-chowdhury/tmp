#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a + 1, a + n + 1);

  for (int i = n; i >= 2; i--) {
    if (a[i] == a[i - 1] and (mp[a[i]] & 1)) continue;
    if (a[i - 1] + k < a[i]) continue;

    if (i + 1 <= n and a[i] == a[i + 1]) {
      if (mp[a[i]] % 2 == 0) continue;
      auto idx = upper_bound(a + 1, a + n + 1, a[i]) - a;
      int nxt = (idx == n + 1) ? 1e9 : a[idx];
      if (a[i] + k < nxt) {
        cout << "YES\n";
        return;
      }
    }
    else {
      int nxt = (i == n) ? 1e9 : a[i + 1];
      if (a[i] + k < nxt) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
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