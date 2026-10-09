#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int a[n + 1], c[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  a[0] = 0, c[0] = 0;

  int last = 0;
  int pref = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      int d1 = c[i] - pref;
      a[i] = d1;
      last = i;

      pref += a[i];

      continue;
    }

    if (pref + a[i] <= c[i]) {
      pref += a[i];
      continue;
    }

    int d1 = c[i] - pref;
    int d2 = a[i];
    int x = d2 - d1;

    pref += a[i];

    pref -= a[last];
    a[last] -= x;
    pref += a[last];
  }

  // cout << a[0] << '\n';

  int mx = a[1], sum = a[1];
  if (a[1] != c[1]) {
    cout << "NO\n";
    return;
  }
  for (int i = 2; i <= n; i++) {
    sum += a[i];
    mx = max(mx, sum);
    if (mx != c[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
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