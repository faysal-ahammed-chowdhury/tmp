#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, MAXV = 1e6 + 9;
int spf[MAXV];
vector<int> g[N];
int n, a[N];
int sz[N], par[N];

void spf_sieve() {
  for (int i = 2; i < MAXV; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MAXV; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MAXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  sz[u] = 1;
  // cout << u << ' ' << p << '\n';
  par[u] = p;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int nC2(int n) {
  if (n < 2) return 0;
  return (n * (n  - 1)) / 2;
}

int nC3(int n) {
  if (n < 3) return 0;
  return (n * (n  - 1) * (n - 2)) / 6;
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    // cout << i <<  ' ' << sz[i] << '\n';
    bool ok = true;
    int x = a[i];
    while (x > 1) {
      int p = spf[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }

      ok &= (pw % 2 == 0);
    }

    if (!ok) continue;

    vector<int> vec;
    int cnt = 0;
    for (int v : g[i]) {
      if (v == par[i]) {
        ans += cnt * (sz[1] - sz[i]);
        cnt += sz[1] - sz[i];
        vec.push_back(sz[1] - sz[i]);
        continue;
      }

      ans += cnt * sz[v];
      cnt += sz[v];
      vec.push_back(sz[v]);
    }

    int cur = nC3(cnt);
    for (auto x : vec) {
      cur -= nC3(x);
      cur -= nC2(x) * (cnt - x);
    } 

    ans += cur;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}