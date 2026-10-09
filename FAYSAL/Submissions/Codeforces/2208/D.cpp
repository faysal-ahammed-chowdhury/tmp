#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
string s[N];
int n;
int cnt[N];
set<int> childs[N];
vector<int> g[N];
bool vis[N][N];
bool vis2[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    cnt[i] = 0;
    childs[i].clear();
    g[i].clear();
    vis2[i] = false;
    for (int j = 0; j <= n; j++) {
      vis[i][j] = false;
    }
  }
}

void dfs(int u, int src) {
  vis[src][u] = true;
  for (auto v : g[u]) {
    if (!vis[src][v]) {
      dfs(v, src);
    }
  }
}

void bfs(int u) {
  queue<int> q;
  q.push(u);

  while (!q.empty()) {
    int top = q.front();
    q.pop();
    if (vis2[top]) continue;
    vis2[top] = true;
    for (auto v : childs[top]) {
      for (int i = 1; i <= n; i++) {
        if (childs[i].find(v) != childs[i].end() and childs[i].find(top) != childs[i].end()) {
          childs[i].erase(v);
        }
      }
      childs[top].insert(v);
      q.push(v);
    }
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '1') {
        cnt[j]++;
        if (i != j) childs[i].insert(j);
      }
    }
  }

  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) vec.push_back(i);
  }

  for (auto v : vec) { // roots
    // cout << v << '\n';
    bfs(v);
  }

  int edge = 0;
  for (int i = 1; i <= n; i++) {
    for (auto v : childs[i]) {
      edge++;
      g[i].push_back(v);
    }
  }

  for (int i = 1; i <= n; i++) {
    dfs(i, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      bool ok1 = vis[i][j] == true and s[i][j] == '1';
      bool ok2 = vis[i][j] == false and s[i][j] == '0';
      if (!(ok1 or ok2) or edge != n - 1) {
        cout << "NO\n";
        return;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto v : childs[i]) {
      g[v].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    vis[1][i] = false;
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    if (!vis[1][i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (auto v : childs[i]) {
      cout << i << ' ' << v << '\n';
    }
  }
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