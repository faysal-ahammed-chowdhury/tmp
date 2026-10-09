#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];

void solve() {
  int x, y; cin >> x >> y;
  if (x > y) {
    cout << "NO\n";
    return;
  }

  int n = x + y;
  if (n % 2 == 0 and x == 0) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  int e = x - (n % 2 == 0);
  int here = 2;
  for (int i = 1; i <= e; i++) {
    cout << 1 << ' ' << here << '\n';
    cout << here << ' ' << here + 1 << '\n';

    here += 2;
  }

  for (int i = here; i <= n; i++) {
    cout << 1 << ' ' << i << '\n';
  }
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