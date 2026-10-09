#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int u, int v, int d) {
  cout << "? " << u << ' ' << v << ' ' << d << endl;
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  int mx = 0;
  int st = 1;

  for (int j = 2; j <= n; j++) {
    while (mx + 1 <= n and query(1, j, mx + 1)) {
      mx++;
      st = j;
    }
  }

  int en = 1;
  for (int j = 1; j <= n; j++) {
    if (j == st) continue;
    while (mx + 1 <= n and query(st, j, mx + 1)) {
      mx++;
      en = j;
    }
  }

  cout << "! " << st << ' ' << en << ' ' << mx << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}