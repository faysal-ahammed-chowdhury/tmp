#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == '1');
  }

  if (s[1] == '1') {
    int ans = n - pref[n];
    cout << ans << '\n';
    return;
  }

  int ans = pref[n];
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') continue;
    int samne_one = pref[i - 1];
    int piche_one = pref[n] - samne_one;
    int piche_zero = (n - i + 1) - piche_one;
    ans = min(ans, samne_one + piche_zero);
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