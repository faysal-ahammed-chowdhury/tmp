#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9;
int n, s, l, a[N];
int mx_possible_in_left[N];
int dp[N];

struct ST {
  pair<int, int> tree[4 * N]; // max, min
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = {a[b], a[b]};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = max(tree[l].first, tree[r].first);
    tree[n].second = min(tree[l].second, tree[r].second);
  }
  int get_last_idx_greater_than_k(int n, int b, int e, int i, int j, int k) {
    if (b > j || e < i) return -1;
    if (tree[n].first <= k) return -1;
    if (b == e) return b;
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int right = get_last_idx_greater_than_k(r, mid + 1, e, i , j, k);
    if (right != -1) return right;
    return get_last_idx_greater_than_k(l, b, mid, i, j, k);
  }
  int get_last_idx_less_than_k(int n, int b, int e, int i, int j, int k) {
    if (b > j || e < i) return -1;
    if (tree[n].second >= k) return -1;
    if (b == e) return b;
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int right = get_last_idx_less_than_k(r, mid + 1, e, i , j, k);
    if (right != -1) return right;
    return get_last_idx_less_than_k(l, b, mid, i, j, k);
  }
} st;

struct ST2 {
  int tree[4 * N];
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
  void upd(int n, int b, int e, int i, int x) {
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
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return inf;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R); 
  }
} st2;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (l > n) {
    cout << -1 << '\n';
    return 0;
  }

  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int idx1 = st.get_last_idx_greater_than_k(1, 1, n, 1, i, a[i] + s);
    int idx2 = st.get_last_idx_less_than_k(1, 1, n, 1, i, a[i] - s);
    if (idx1 == -1) idx1 = 1;
    else idx1++;
    if (idx2 == -1) idx2 = 1;
    else idx2++;
    mx_possible_in_left[i] = max({mx_possible_in_left[i - 1], idx1, idx2});
  }

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = inf;
  }

  st2.build(1, 1, n);
  st2.upd(1, 1, n, 1, 0);
  for (int i = 1; i <= n; i++) {
    int lo = mx_possible_in_left[i];
    int hi = i - l + 1;
    // cout << i << ' ' << lo << ' ' << hi << '\n';
    dp[i] = st2.query(1, 1, n, lo, hi) + 1;
    st2.upd(1, 1, n, i + 1, dp[i]);
  }

  int ans = dp[n];
  if (ans >= inf) ans = -1;
  cout << ans << '\n';

  return 0;
}