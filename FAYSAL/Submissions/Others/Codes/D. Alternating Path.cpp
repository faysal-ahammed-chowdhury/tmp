#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define RED 1
#define GREEN 2

const int N = 2e5 + 9;
vector<int> g[N];
int n, m;
bool vis[N];
int col[N];
bool possible;
int green, red;

void clr(int n) {
  green = 0;
  red = 0;
  possible = true;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    col[i] = 0;
  }
}

void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      if (col[u] == RED) {
        col[v] = GREEN;
        green++;
      }
      else {
        col[v] = RED;
        red++;
      }
      dfs(v);
    }
    else if (col[u] == col[v]) {
      possible = false;
    }
  }
}

void solve() {
  cin >> n >> m;
  clr(n);
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      red = 1;
      green = 0;
      possible = true;
      col[i] = RED;
      dfs(i);

      if (possible) ans += max(red, green);
    }
  }

  cout << ans << '\n';
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