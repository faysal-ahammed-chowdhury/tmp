#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9, inf = 1e9;

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans_right[n + 1], ans_left[n + 1];
  memset(ans_left, 0, sizeof ans_left);
  memset(ans_right, 0, sizeof ans_right);

  st.build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    if (i + 1 <= n and a[i] > a[i + 1]) {
      int idx = st.query(1, 1, n, a[i] + 1, n);

      if (idx == inf) ans_right[i] = n - i;
      else ans_right[i] = idx - i - 1 + ans_right[idx];
    }
    else {
      ans_right[i] = i + 1 <= n ? ans_right[i + 1] : 0;
    }

    // cout << i << ' ' << ans_right[i] << '\n';

    st.upd(1, 1, n, a[i], i);
  }

  reverse(a + 1, a + n + 1);

  st.build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    if (i + 1 <= n and a[i] > a[i + 1]) {
      int idx = st.query(1, 1, n, a[i] + 1, n);

      if (idx == inf) ans_left[i] = n - i;
      else ans_left[i] = idx - i - 1 + ans_left[idx];
    }
    else {
      ans_left[i] = i + 1 <= n ? ans_left[i + 1] : 0;
    }

    // cout << i << ' ' << ans_left[i] << '\n';

    st.upd(1, 1, n, a[i], i);
  }

  reverse(ans_left + 1, ans_left + n + 1);

  int ans = n;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, ans_left[i] + ans_right[i]);
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