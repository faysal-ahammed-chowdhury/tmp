#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  int freq[m + 1];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  sort(a + 1, a + n + 1);

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int cur = freq[i];
    if (i + i <= m) cur += freq[i + i];
    int idx = upper_bound(a + 1, a + n + 1, i) - a;
    int boro = n - idx + 1;
    cur += boro;
    ans = max(ans, cur);
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