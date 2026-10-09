#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int a[N], b[N];
int n;
vector<int> g[N];

bool cmp(pair<ll, ll> a, pair<ll, ll> b) { 
  ll ans1 = (a.first * b.first) + (a.first * b.second) + a.second;
  ll ans2 = (b.first * a.first) + (b.first * a.second) + b.second;
  return ans1 < ans2;
}

pair<ll, ll> dfs(int u, int p) {
  vector<pair<ll, ll>> vec;
  for (auto v : g[u]) {
    if (v == p) continue;
    auto [x, y] = dfs(v, u);
    vec.push_back({x, y});
  }

  sort(vec.begin(), vec.end(), cmp);
  ll cur_a = a[u], cur_b = b[u];

  for (auto [x, y] : vec) {
    cur_a *= x;
    cur_b *= x;
    cur_b += y;
  }

  return {cur_a, cur_b};
}

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // vector<pair<int, int>> v;
  // v.push_back({4, 2});
  // v.push_back({2, 2});
  // sort(v.begin(), v.end(), cmp);
  // for (auto [x, y] : v) {
  //   cout << x << ' ' << y << '\n';
  // }

  cout << dfs(1, 0).second << '\n';
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