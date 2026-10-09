#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int a[N];
int val[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += lazy[n] * (e - b + 1);
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
      tree[n] = val[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j, int x) {
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
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st;


void solve() {
  int n; cin >> n;
  o_set<pair<int, int>> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    val[i] = n + 1;
    se.insert({a[i], i});
  }

  for (int i = 1; i <= a[n]; i++) {
    val[i] = n;
  }

  st.build(1, 1, n);

  int ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    int l = 1, r = a[i];
    int cnt = r - l + 1;
    int sum = st.query(1, 1, n, l, r) - cnt;
    int here = cnt * i;
    ans += sum - here;

    st.upd(1, 1, n, l, r, -1);
  }

  int tmp = ans;

  st.build(1, 1, n);

  for (int i = n; i >= 1; i--) {
    se.erase({a[i], i});
    if (i == n) {
      int cur = tmp;
      cur += se.order_of_key({a[i], -1});
      ans = max(ans, cur);
      continue;
    }

    int cur = tmp;
    int sum = st.query(1, 1, n, a[i], a[i]) - 1;
    int here = i;
    cur -= sum - here;

    cur += se.order_of_key({a[i], -1});

    ans = max(ans, cur);

    st.upd(1, 1, n, 1, a[i], -1);
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