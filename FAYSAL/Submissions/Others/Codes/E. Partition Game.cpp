#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 35000 + 9;
const ll inf = 1e18;
int n, k, a[N];
ll dp[N], ndp[N];

struct ST {
  ll tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = dp[b - 1];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, ll x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = min(tree[l], tree[r]);
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n  >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i] = inf;
  }
  dp[0] = 0;
  st.build(1, 1, n);

  for (int j = 1; j <= k; j++) {
    int last[n + 1];
    memset(last, -1, sizeof last);
    for (int i = 1; i <= n; i++) {
      int add = -1, idx = -1;
      if (last[a[i]] != -1) {
        add = i - last[a[i]];
        idx = last[a[i]];
      }
      if (idx > 0) st.upd(1, 1, n, 1, idx, add);
      ndp[i] = st.query(1, 1, n, 1, i);
      last[a[i]] = i;
    }
    swap(dp, ndp);
    st.build(1, 1, n);
  }

  cout << dp[n] << '\n';

  return 0;
}