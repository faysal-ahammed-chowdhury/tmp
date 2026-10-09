#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];

ll lcm(ll a, ll b) {
  return a * b / __gcd(a, b);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int gc1 = (i + 1 <= n) ? __gcd(a[i], a[i + 1]) : 1;
    int gc2 = (i - 1 >= 1) ? __gcd(a[i], a[i - 1]) : 1;
    ll lc = lcm(gc1, gc2);
    // cout << i << ' ' << lc << '\n';
    if (lc < a[i]) ans++;
  }
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