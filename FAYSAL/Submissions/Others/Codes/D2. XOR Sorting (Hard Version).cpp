#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 9, inf = 2e9;
int n, a[N];

struct node {
  int mn; int mx;
  int ans;
};

struct ST {
  node tree[4 * N];

  node merge(node l, node r, int sz) {
    node tmp;
    tmp.mn = min(l.mn, r.mn);
    tmp.mx = max(l.mx, r.mx);
    tmp.ans = max(l.ans, r.ans);
    if (l.mx > r.mn) {
      tmp.ans = sz;
    }
    return tmp;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].mn = a[b];
      tree[n].mx = a[b];
      tree[n].ans = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r], e - b + 1);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].mn = x;
      tree[n].mx = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r], e - b + 1);
  }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) {
      node tmp;
      tmp.mn = inf;
      tmp.mx = 0;
      tree[n].ans = 1;
      return tmp;
    }
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R, e - b + 1);
  }
} st;

void solve() {
  int q; cin >> n >> q;
  int old = n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int msb = __lg(n);
  if (__builtin_popcount(n) > 1) {
    n = (1 << (msb + 1));
  }

  for (int i = old + 1; i <= n; i++) {
    a[i] = inf;
  }

  st.build(1, 1, n);
  cout << st.query(1, 1, n, 1, n).ans / 2 << '\n';

  while (q--) {
    int i, x; cin >> i >> x;
    i++;
    st.upd(1, 1, n, i, x);
    cout << st.query(1, 1, n, 1, n).ans / 2 << '\n';
  }
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