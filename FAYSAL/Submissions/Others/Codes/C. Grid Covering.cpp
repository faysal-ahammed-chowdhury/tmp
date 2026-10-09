#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

void solve() {
  int n, m, a, b; cin >> n >> m >> a >> b;
  if (__gcd(n, a) == 1 and __gcd(m, b) == 1 and (n * m) <= 2 * lcm(n, m)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}