#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll ans = (1ll * n * (n - 1)) / 2;
  cout << ans << '\n';

  return 0;
}