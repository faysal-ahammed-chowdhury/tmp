#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
const ll inf = 1e18;
int n, a[N];
ll pref[N];
int mx_right[N];

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]); 
  }
  void upd(int n, int b, int e, int i, ll x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]); 
  }
  ll query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return inf;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

bool ok(ll mx) {
  for (int i = 1; i <= n; i++) {
    ll x = pref[i - 1] + mx;
    auto it = upper_bound(pref + 1, pref + n + 1, x);
    --it;
    int idx = it - pref;
    mx_right[i] = idx;
    // cout << i << ' ' << idx << '\n';
  }

  st.build(1, 1, n + 1);
  for (int i = n; i >= 0; i--) {
    int idx = i == n ? n + 1 : mx_right[i + 1] + 1;
    ll my_best = a[i] + st.query(1, 1, n + 1, i + 1, idx);
    if (i > 0) st.upd(1, 1, n + 1, i, my_best);
    if (i == 0) return my_best <= mx;
  }

  return false;
}

void solve() {
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
    mx = max(mx, a[i]);
  }

  // cout << ok(11) << '\n';
  ll l = mx, r = 1e14, ans = inf;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
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