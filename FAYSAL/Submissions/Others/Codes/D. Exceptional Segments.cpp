#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define int long long

const int mod = 998244353;

ll f0(ll n) {
  n += 1;
  return n / 4;
}

ll f1(ll n) {
  n += 3;
  return n / 4;
}

void solve() {
  ll n, x; cin >> n >> x;

  int left = f0(x - 1);
  int right = f0(n) - left;
  left++;

  int ans = (left % mod) * (right % mod) % mod;

  left = f1(x - 1);
  right = f1(n) - left;

  ans += (left % mod) * (right % mod) % mod;
  ans %= mod;

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