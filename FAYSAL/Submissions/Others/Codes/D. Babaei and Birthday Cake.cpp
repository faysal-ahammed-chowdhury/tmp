#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double PI = acos(-1);
const int N = 1e5 + 9;
int n;
int R[N], H[N];
ll dp[N];

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, ll x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = max(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  ll query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<ll> v;
  for (int i = 1; i <= n; i++) {
    cin >> R[i] >> H[i];
    ll volume = 1ll * H[i] * R[i] * R[i];
    v.push_back(volume);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  st.build(1, 1, v.size());
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll volume = 1ll * H[i] * R[i] * R[i];
    int comp = lower_bound(v.begin(), v.end(), volume) - v.begin() + 1;
    dp[i] = volume + st.query(1, 1, v.size(), 1, comp - 1);
    st.upd(1, 1, v.size(), comp, dp[i]);
    ans = max(ans, dp[i]);
  }

  long double dans = (long double)PI * ans;
  cout << fixed << setprecision(10);
  cout << dans << '\n';

  return 0;
}