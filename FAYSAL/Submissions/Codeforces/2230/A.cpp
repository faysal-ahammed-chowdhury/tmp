#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, a, b; cin >> n >> a >> b;

  int ans1 = n * a;
  int grp = n / 3;
  int ans2 = b * grp;

  int rem = n % 3;
  if (rem) {
    ans2 += min(b, rem * a);
  }

  cout << min(ans1, ans2) << '\n';
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