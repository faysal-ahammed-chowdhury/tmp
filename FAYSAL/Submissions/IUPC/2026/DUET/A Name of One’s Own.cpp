#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 3e5 + 9, mod = 998244353;
int a[N], b[N];

struct DSU {
  vector<int> par, sz;
  int c;
  vector<bool> cycle;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1), cycle.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      cycle[i] = false;
    }
    c = n;
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() { // number of connected components
    return c;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    cycle[i] = cycle[i] or cycle[j];
    return i;
  }
};

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n; cin >> n;

  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    vec.push_back(a[i]);
    vec.push_back(b[i]);
  }

  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

  DSU dsu(n + n);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int u = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    int v = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin() + 1;
    if (dsu.same(u, v)) {
      bool has_cycle = dsu.cycle[dsu.find(u)] or dsu.cycle[dsu.find(v)];
      if (has_cycle) ans = 0;
      else {
        int div = dsu.get_size(u);
        dsu.cycle[dsu.find(u)] = true;
        ans = 1ll * ans * power(div, mod - 2, mod) % mod;
        ans = 1ll * ans * 2 % mod;
      }
    }
    else {
      bool both_has_cycle = dsu.cycle[dsu.find(u)] and dsu.cycle[dsu.find(v)];
      if (both_has_cycle) {
        ans = 0;
      }

      int div1 = dsu.get_size(u);
      int div2 = dsu.get_size(v);

      bool has_cycle1 = dsu.cycle[dsu.find(u)];
      bool has_cycle2 = dsu.cycle[dsu.find(v)];
      bool has_cycle = has_cycle1 or has_cycle2;

      if (has_cycle1) div1 = 2;
      if (has_cycle2) div2 = 2;

      dsu.merge(u, v);
      int mul = has_cycle ? 2 : dsu.get_size(u);

      ans = 1ll * ans * power(div1, mod - 2, mod) % mod;
      ans = 1ll * ans * power(div2, mod - 2, mod) % mod;
      ans = 1ll * ans * mul % mod;
    }

    cout << ans << ' ';
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