#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  n += n;
  int a[n + 1];
  int idx1 = -1, idx2 = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      if (idx1 == -1) idx1 = i;
      else idx2 = i;
    }
  }

  set<int> se;
  for (int i = 0; i <= n; i++) {
    se.insert(i);
  }

  int l = idx1, r = idx1;
  while (l >= 1 and r <= n) {
    if (a[l] != a[r]) break;
    se.erase(a[l]);
    se.erase(a[r]);

    l--, r++;
  }

  int ans = *se.begin();
  for (int i = 0; i <= n; i++) {
    se.insert(i);
  }

  l = idx2, r = idx2;
  while (l >= 1 and r <= n) {
    if (a[l] != a[r]) break;
    se.erase(a[l]);
    se.erase(a[r]);

    l--, r++;
  }

  ans = max(ans, *se.begin());

  for (int i = 0; i <= n; i++) {
    se.insert(i);
  }

  bool ok = true;
  l = idx1, r = idx2;
  while (l <= r) {
    if (a[l] != a[r]) {
      ok = false; 
      break;
    }

    se.erase(a[l]);
    se.erase(a[r]);

    l++, r--;
  }

  while (ok and l >= 1 and r <= n) {
    if (a[l] != a[r]) break;
    se.erase(a[l]);
    se.erase(a[r]);

    l--, r++;
  }

  if (ok) ans = max(ans, *se.begin());
  cout << ans << '\n';
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