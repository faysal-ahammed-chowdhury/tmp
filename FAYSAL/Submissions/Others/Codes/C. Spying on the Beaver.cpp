#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 1e5 + 9;
int n, m;
bool a[N];
vector<int> g[N];
int ans[N];
set<int> se;

void clr(int n) {
  se.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    a[i] = false;
    ans[i] = 0;
  }
}

bool dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    bool need = dfs(v, u);
    ans[u] += ans[v];
    if (need) {
      ans[u]++;
      se.insert(v);
    }
  }

  return a[u];
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    a[x] = true;
  }

  bool need = dfs(1, 0);
  int here = ans[1];
  if (a[1] == false) {
    here--;
    se.erase(se.begin());
  }

  cout << here << ' ';
  for (auto x : se) cout << x << ' ';
  cout << '\n';
  // assert(se.size() == here);
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