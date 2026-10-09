#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int pref[N], pref2[N];

void solve() {
  int n, q; cin >> n >> q;
  string s, t; cin >> s >> t;
  s = '.' + s, t = '.' + t;

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    pref2[i] = pref2[i - 1];
    if (s[i] == t[i]) pref[i] = pref[i - 1] + 1;
    else if (s[i] == '1') pref2[i] = pref2[i - 1] + 1;
    else pref2[i] = pref2[i - 1] - 1;
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int x = pref[r] - pref[l - 1];
    int y = abs(pref2[r] - pref2[l - 1]);
    if (y <= x) cout << "YES\n";
    else cout << "NO\n";
  }
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