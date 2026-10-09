#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9;
int n, c[N], p[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> p[i];
  }

  double ans = 0;
  for (int i = n; i >= 1; i--) {
    ans = max(ans, c[i] + (ans * (1.0 - (p[i] / 100.0))));
  }

  cout << fixed << setprecision(10);
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