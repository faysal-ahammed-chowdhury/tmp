#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5 + 9, inf = 1e12;
int dp[N][30];

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
      tree[n] = x + b;
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

int calc(int x) {
  int ans = 0;
  while (x) {
    ans++;
    if (x & 1) x--;
    else x /= 2;
  }
  return ans;
}

void f(int x, int k) {
  int ans = (x % (1ll << k) == 0) ? calc(x) : inf;
  int cur = st.query(1, 1, 2e5, x + 1, 2e5);
  ans = min(ans, cur - x);
  if (x % (1ll << k) == 0) st.upd(1, 1, 2e5, x, ans);
  dp[x][k] = ans;
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = inf;
  for (int k = 0; k < 25; k++) {
    int x = 1ll << k;
    int cur = k;
    for (int i = 1; i <= n; i++) {
      cur += dp[a[i]][k] - k;
    }
    ans = min(ans, cur);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int k = 0; k <= 25; k++) {
    st.build(1, 1, 2e5);
    for (int i = 2e5; i >= 1; i--) {
      f(i, k);
    }
  }

  // cout << dp[1][1] << '\n';
  // return 0;

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}