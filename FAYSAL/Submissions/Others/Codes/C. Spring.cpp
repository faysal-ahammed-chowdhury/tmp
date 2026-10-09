#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

ll f(ll a, ll b, ll c, ll m) {
  ll x = lcm(a, b);
  ll y = lcm(a, c);
  ll z = lcm(a, lcm(b, c));
  ll two_litre = (m / z);
  ll three_litre = (m / x) + (m / y) - two_litre * 2;
  ll six_litre = (m / a) - two_litre - three_litre;
  // cout << (m / x) + (m / y) << '\n';
  ll ans = two_litre * 2 + three_litre * 3 + six_litre * 6;
  return ans;
}

void solve() {
  ll a, b, c, m; cin >> a >> b >> c >> m;
  // cout << f(a, b, c, m) << '\n';
  cout << f(a, b, c, m) << ' ' << f(b, a, c, m) << ' ' << f(c, a, b, m) << '\n';
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