#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 2e5 + 9, LOG = 20;
vector<int> g[N];
int n;
string s;
int par[N][LOG], depth[N];
int disc[N + N], finish[N + N];
int timer;
int freq[N + N][26];

void dfs(int u, int p) {
  disc[u] = ++timer;
  freq[disc[u]][s[u - 1] - 'a'] = 1;
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = ++timer;
  freq[finish[u]][s[u - 1] - 'a'] = -1;
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

int dist(int u, int v) {
  int l = lca(u, v);
  return (depth[u] - depth[l]) + (depth[v] - depth[l]);
}

// kth node from u to v, 0th node is u
int kth(int u, int v, int k) {
  int l = lca(u, v);
  int d = dist(u, v);
  assert(k <= d);
  if (depth[l] + k <= depth[u]) {
    return kth(u, k);
  }
  k -= depth[u] - depth[l];
  return kth(v, depth[v] - depth[l] - k);
}

bool ok(int mid, int u, int v, char c) {
  int node = kth(u, v, mid);
  // cout << mid << ' ' << u << ' ' << node << ' ' << c << '\n';
  int l = disc[node], r = disc[u];
  if (l > r) swap(l, r);

  int cnt = freq[r][c - 'a'] - freq[l - 1][c - 'a'];

  return cnt >= 1;
}

int f(int u, int v, string &t) {
  int ans = 0;

  for (int i = 0; i < t.size(); i++) {
    char c = t[i];
    int l = 0, r = dist(u, v), mn = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, u, v, c)) {
        mn = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    if (mn == -1) return ans;
    ans++;

    // cout << u << ' ' << mn << '\n';

    int node = kth(u, v, mn);
    if (node == v) return ans;
    u = kth(node, v, 1);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q >> s;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);

  for (int i = 1; i <= n + n; i++) {
    for (int j = 0; j < 26; j++) {
      freq[i][j] += freq[i - 1][j];
    }
  }

  // for (auto x : treee[4][0]) {
  //   cout << x << ' ';
  // }
  // string tmp = "cbb";
  // cout << f(3, 1, tmp) << '\n';
  // return 0;

  while (q--) {
    int u, v; cin >> u >> v;
    string t; cin >> t;
    string rev = t;
    reverse(rev.begin(), rev.end());

    int l = lca(u, v);
    int ans = f(u, l, t);
    if (v != l) ans += f(v, kth(l, v, 1), rev);
    // cout << ans << '\n';
    if (ans >= t.size()) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}