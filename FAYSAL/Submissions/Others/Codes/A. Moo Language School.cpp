#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int ans = 0;
  int nbyk = n / k;
  for (int i = 1; i <= nbyk; i++) {
    int st = (k * (i - 1)) + 1;
    int en = st + k - 1;
    bool ok = true;
    for (int j = st; j <= en; j++) {
      ok &= s[j] == '1';
    }
    // cout << st << ' ' << en << '\n';
    ans += ok;
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