#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

ll s, m;
ll cnt[70];

bool ok(ll mx) {
  ll cnt2[70];
  for (int k = 0; k <= 60; k++) {
    cnt2[k] = cnt[k];
  }
  for (int k = 60; k >= 0; k--) {
    ll extra = CHECK(m, k) ? max(0ll, cnt2[k] - mx) : cnt2[k];
    if (k > 0) {
      cnt2[k - 1] += extra * 2;
    }
  }

  if (cnt2[0] > 0 and !CHECK(m, 0)) return false;
  return cnt2[0] <= mx;
}

void solve() {
  cin >> s >> m;
  memset(cnt, 0, sizeof cnt);
  ll mx = 0;
  for (int k = 60; k >= 0; k--) {
    if (CHECK(s, k)) {
      cnt[k] += 1;
    }
    if (!CHECK(m, k) and k > 0) {
      cnt[k - 1] += cnt[k] * 2;
      cnt[k] = 0;
    }

    mx = max(mx, cnt[k]);
  }

  if (cnt[0] > 0 and !CHECK(m, 0)) {
    cout << -1 << '\n';
    return;
  }

  ll l = 1, r = mx, ans = -1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }

  cout << ans << '\n';
  // cout << ok(3) << '\n';
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