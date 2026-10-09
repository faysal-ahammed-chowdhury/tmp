#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9, mod = 676767677;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  vector<int> v[m];
  int mn[n + 1], mx[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
    mn[i] = mx[i] = inf;
    if (a[i] == 0) mn[i] = 0, mx[i] = 0;
  }

  int cnt = v[0].size();
  int mx_cur = 0;
  for (int i = 1; i < m; i++) {
    for (auto idx : v[i]) {
      int here = (idx + 1 <= n) ? a[idx + 1] : inf;
      if (idx - 1 >= 1) here = min(here, a[idx - 1]);
      if (here >= i) {
        cout << 0 << '\n';
        return;
      }
      if (here == i - 1) {
        mn[idx] = 1, mx[idx] = cnt;
      }
      else {
        mn[idx] = mx_cur + 1, mx[idx] = cnt;
      }
    }

    mx_cur = cnt;
    cnt += v[i].size();
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    assert(mn[i] < inf);
    assert(mx[i] < inf);
    assert(mn[i] <= mx[i]);
    int d = mx[i] - mn[i] + 1;
    ans = 1ll * ans * d % mod;
  }
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