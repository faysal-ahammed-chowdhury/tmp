#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int inf = 1e18;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  int pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == '(');
  }

  int suff[n + 2];
  suff[n + 1] = 0;

  int idx[n + 5];
  for (int i = 0; i <= n; i++) {
    idx[i] = n + 1;
  }

  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + (s[i] == ')');
    idx[suff[i]] = i;

    // cout << suff[i] << ' ' << idx[suff[i]] << '\n';
  }

  int ans = inf;

  int l = 0, r = n + 1;
  for (int i = 1; i <= n; i++) {
    int rem = k - pref[i - 1];
    if (rem < 0) continue;
    int en = idx[rem] - 1;

    int cur = 0;
    int sum = 0;
    for (int j = i; j <= en; j++) {
      int x = ((sum > 0) and (s[j] == ')')) ? 2 : 0;
      sum += (s[j] == '(') ? +1 : -1;
      sum = max(sum, 0ll);
      cur += x;
    }

    ans = min(ans, cur);
    if (ans == cur) {
      l = i, r = en;
    }
    // cout << i << ' ' << en << ' ' << cur << '\n';
  }

  // cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') {
      if (i < l) cout << 1;
      else cout << 0;
    }
    else {
      if (i > r) cout << 1;
      else cout << 0;
    }
  }

  cout << '\n';
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