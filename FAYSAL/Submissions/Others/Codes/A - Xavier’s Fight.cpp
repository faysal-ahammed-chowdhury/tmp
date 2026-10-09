#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n;
  ll ans = (1ll * n * (n + 1)) / 2;
  cout << ans << ".000\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}