#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  if (k == 0) {

  }
  int need = k ^ n;
  if (need >= n) {
    int msb = __lg(need);
    int need2 = (1 << msb);
    need ^= need2;
    if (need2 >= n) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    for (int i = 1; i < n; i++) {
      if (i == need) continue;
      if (i == need2) continue;
      cout << i << ' ';
    }
    cout << 0 << ' ';
    if (need != 0) cout << need << ' ';
    if (need2 != 0) cout << need2;
    cout << '\n';

    return;
  }
  cout << "YES\n";
  for (int i = 1; i < n; i++) {
    if (i == need) continue;
    cout << i << ' ';
  }
  cout << 0 << ' ';
  if (need != 0) cout << need << '\n';
  else cout << '\n';
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