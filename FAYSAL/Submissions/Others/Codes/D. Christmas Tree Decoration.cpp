#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 55, mod = 998244353;
int n, a[N], b[N];

bool ok(int mn) {
  int need = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < mn) {
      need += mn - a[i];
    }
  }

  return a[0] >= need;
}

void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(a + 1, a + n + 1);

  int l = 0, r = 2e6, mx_mn = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      mx_mn = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }

  int mx = a[n], mx_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mx) mx_cnt++;
  }

  int rem = a[0];
  for (int i = 1; i <= n; i++) {
    if (a[i] < mx_mn) {
      rem -= mx_mn - a[i];
      a[i] = mx_mn;
    }
  }

  sort(a + 1, a + n + 1);

  if (a[n] - a[1] >= 2) {
    cout << 0 << '\n';
    return;
  }

  if (a[n] > mx or (a[1] == a[n])) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = 1ll * ans * i % mod;
    }
    cout << ans << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (rem == 0) break;
    a[i]++;
    rem--;
  }

  sort(a + 1, a + n + 1);

  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[a[i]]++;
  }

  int ans = 1;
  int now = mp[mx];
  // cout << now << '\n';
  for (int i = 1; i <= mx_cnt; i++) {
    ans = 1ll * ans * now % mod;
    now--;
  }
  for (int i = 1; i <= n - mx_cnt; i++) {
    ans = 1ll * ans * i % mod;
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