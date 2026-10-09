#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int a, b; cin >> a >> b;
  if (a > b) swap(a, b);
  if (__gcd(a, b) == a) cout << "true\n";
  else cout << "false\n";
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