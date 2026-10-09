#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = lazy[n] * (e - b + 1);
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
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
      lazy[n] = x;
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
  st.build(1, 1, n);
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= 0) continue;
    int l = max(1, i - a[i] + 1), r = min(n, i + a[i] - 1);
    // cout << l << ' ' << r << '\n';
    st.upd(1, 1, n, l, r, 1);
  }

  int ans[n + 1];
  int dis[n + 1];
  for (int i = 1; i <= n; i++) {
    if (st.query(1, 1, n, i, i) > 0) ans[i] = 1;
    else ans[i] =  0;
    dis[i] = n + 5;
    // cout << i << ' ' << ans[i] << '\n';
  }
  // cout << '\n';

  queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 and ans[i] != 0) {
      cout << -1 << '\n';
      return;
    }
    if (ans[i] == 0) {
      // cout << i << '\n';
      q.push({0, i});
      dis[i] = 0;
    }
  }

  while (!q.empty()) {
    int d = q.front().first;
    int idx = q.front().second;
    q.pop();

    // cout << idx << ' ' << d << '\n';

    if (idx + 1 <= n)  {
      if (dis[idx + 1] > d + 1) q.push({d + 1, idx + 1});
      dis[idx + 1] = min(dis[idx + 1], d + 1);
    }
    if (idx - 1 <= n)  {
      if  (dis[idx - 1] > d + 1) q.push({d + 1, idx - 1});
      dis[idx - 1] = min(dis[idx - 1], d + 1);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) continue;
    if (a[i] != dis[i]) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) ans[i] = 1;
    else ans[i] = 0;
    cout << ans[i];
  }
  cout << '\n';
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