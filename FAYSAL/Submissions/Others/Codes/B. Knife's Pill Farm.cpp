#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  priority_queue<int> pq;
  ll ans = -1e18;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    if (pq.size() == m - 1) {
      ans = max(ans, 1ll * m * a[i] - sum);
    }

    pq.push(a[i]);
    sum += a[i];
    if (pq.size() == m) {
      sum -= pq.top();
      pq.pop();
    }
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