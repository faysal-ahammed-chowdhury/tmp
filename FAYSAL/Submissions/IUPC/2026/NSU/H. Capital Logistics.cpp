#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, k;
vector<int> g[N];
int a[N];
int ans[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  ans[u] = a[u];
  int mx = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    mx = max(mx, ans[v]);
  }

  ans[u] += mx;
}

int need;
void dfs2(int u, int p, int banate_hobe) {
  if (ans[u] <= banate_hobe) return;
  int x = ans[u] - banate_hobe;
  int y = min(x, a[u]);
  need += y;

  int mx = ans[u] - a[u] - (x - y);
  for (auto v : g[u]) {
    if (v == p) continue;
    if (ans[v] > mx) {
      dfs2(v, u, mx);
    }
  }
}

bool ok(int mid) {
  need = 0;
  dfs2(1, 0, mid);
  return need <= k;
}

void solve() {
  cin >> n >> k;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dfs(1, 0);
  // cout << ans[1] << '\n';

  int l = 0, r = ans[1], tmp = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      tmp = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }

  assert(tmp != -1);
  cout << tmp << '\n';
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