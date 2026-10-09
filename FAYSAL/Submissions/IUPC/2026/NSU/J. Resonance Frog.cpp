#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

const int N = 1e6 + 9, inf = 1e9;
int n, a[N], b[N], max_jump[N];
int dp[N];

struct ST {
  int tree[4 * N];
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
} st;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  gp_hash_table<int, vector<int>, custom_hash> mp;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    mp[b[i]].push_back(i);
  }

  gp_hash_table<int, int, custom_hash> last;
  gp_hash_table<int, int, custom_hash> freq;
  for (int i = 1; i <= n; i++) {
    int x = last.find(a[i]) != last.end() ? i - last[a[i]] : 1;
    max_jump[i] = x; 

    last[b[i]] = i;
    freq[b[i]]++;
  }

  gp_hash_table<int, int, custom_hash> start;
  int tmp = 1;
  for (auto [x, cnt] : freq) {
    start[x] = tmp;
    tmp += cnt;
  }

  gp_hash_table<int, int, custom_hash> freq2 = freq;

  st.build(1, 1, n);
  dp[n] = 0;
  st.upd(1, 1, n, start[b[n]] + freq[b[n]] - 1, 0);
  freq2[b[n]]--;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = 1 + dp[i + 1];
    int x = max_jump[i];
    if (x > 1) {
      if (i + x <= n) dp[i] = min(dp[i], 1 + dp[i + x]);

      if (mp.find(a[i]) != mp.end()) {
        int cnt = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), i + x - 1) - mp[a[i]].begin();
        dp[i] = min(dp[i], 1 + st.query(1, 1, n, start[a[i]], start[a[i]] + cnt - 1));
      }
    }

    st.upd(1, 1, n, start[b[i]] + freq2[b[i]] - 1, dp[i]);
    freq2[b[i]]--;
    // cout << i << ' ' << max_jump[i] << ' ' << dp[i] << '\n';
  }

  cout << dp[1] << '\n';
  assert(dp[1] <= n - 1);
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