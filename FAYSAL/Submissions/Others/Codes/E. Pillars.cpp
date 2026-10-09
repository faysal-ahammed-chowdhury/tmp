#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int n, d;
ll a[N];
int dp[N], prv[N];

struct ST {
  pair<int, int> tree[12 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x, int y) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      if (x >= tree[n].first) {
        tree[n] = {x, y};
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x, y);
    upd(r, mid + 1, e, i, x, y);
    tree[n] = max(tree[l], tree[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d;
  vector<ll> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
    v.push_back(a[i] - d);
    v.push_back(a[i] + d);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  st.build(1, 1, v.size());
  int ans = 0, idx = -1;
  for (int i = 1; i <= n; i++) {
    int comp = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    int l = lower_bound(v.begin(), v.end(), a[i] - d) - v.begin() + 1;
    int r = lower_bound(v.begin(), v.end(), a[i] + d) - v.begin() + 1;

    auto p1 = st.query(1, 1, v.size(), 1, l);
    auto p2 = st.query(1, 1, v.size(), r, v.size());
    dp[i] = 1 + max(p1.first, p2.first);
    st.upd(1, 1, v.size(), comp, dp[i], i);
    if (p1.first >= p2.first) prv[i] = p1.second;
    else prv[i] = p2.second;
    if (dp[i] >= ans) {
      ans = dp[i];
      idx = i;
    }
  }

  cout << ans << '\n';
  vector<int> vec;
  int cur = idx;
  while (ans--) {
    vec.push_back(idx);
    idx = prv[idx];
  }

  reverse(vec.begin(), vec.end());
  for (auto x : vec) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}