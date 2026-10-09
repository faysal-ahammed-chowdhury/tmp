#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9, MAX = 3e5 + 1;
int n, k, a[N];
int dp[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]); 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = max(tree[n], x); 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]); 
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R); 
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
  }

  int ans = 0;
  st.build(1, 1, MAX);
  for (int i = 1; i <= n; i++) {
    int x = st.query(1, 1, MAX, max(0, a[i] - k), min(MAX, a[i] + k));
    dp[i] = max(1, 1 + x);

    st.upd(1, 1, MAX, a[i], dp[i]);
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';

  return 0;
}