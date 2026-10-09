#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  int freq[m + 4];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  for (int i = 1; i <= m; i++) {
    freq[i] += freq[i - 1];
  }

  ll ans[m + 3];
  memset(ans, 0, sizeof ans);

  for (int k = 1, tmp = 1; k <= 18 and tmp <= m; k++, tmp *= 2) {
    bool first = true;
    for (int x = 1; first or (x <= (m / (1ll << k))); x++) {
      first = false;
      ll cur = 0;
      int mx = x * (1ll << k);
      for (int j = 1; j <= m; j++) {
        int st = j * x;
        int en = j * x + x - 1;
        if (st > mx) break;
        en = min(en, mx);
        // cout << st << ' ' << en << ' ' << j << '\n';
        cur += 1ll * (freq[en] - freq[st - 1]) * (j);
      }

      int en = (x * (1ll << k));
      // cout << en << '\n';
      if (en + 1 <= m) {
        cur += 1ll * (freq[m] - freq[en]) * ((en / x) - 1);
      }
      ans[k] = max(ans[k], cur);

    }
  }

  for (int i = 1; i <= m; i++) {
    ans[i] = max(ans[i - 1], ans[i]);
    cout << ans[i] << ' ';
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