#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e18;
int n, k;
vector<int> vec;
string s;
ll dp[N];

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = inf; 
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
} st, st2;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> s;
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') vec.push_back(i);
  }

  dp[n + 1] = 0;
  st.upd(1, 1, n + 1, n + 1, 0);
  st2.build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    ll &ans = dp[i];
    ans = inf;

    ans = min(ans, i + dp[i + 1]);
    if (s[i] == '1') {
      ans = min(ans, i + st.query(1, 1, n + 1, i + 1, min(i + k + 1, n + 1)));
    }
    ans = min(ans, st2.query(1, 1, n, i + 1, min(n, i + k)));

    st.upd(1, 1, n + 1, i, ans);
    if (s[i] == '1') st2.upd(1, 1, n, i, i + st.query(1, 1, n + 1, i + 1, min(i + k + 1, n + 1)));
  }

  cout << dp[1] << '\n';

  return 0;
}