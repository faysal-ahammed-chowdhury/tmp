#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, k;
vector<int> g[N];
int par[N];
int ans;

struct node {
  map<int, int> mp;
  int add;
  node() {
    add = 0;
  }
} nodes[N];

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  bool swapped = false;
  if (nodes[u].mp.size() >= nodes[v].mp.size()) {
    swap(u, v);
    swapped = true;
  }
  for (auto [d, cnt] : nodes[u].mp) {
    int actual_d = d + nodes[u].add + 1;
    int need = k - actual_d;
    ans += nodes[v].mp[need - nodes[v].add] * cnt;
  }

  // swapped hole normal way (mone rakhar jonno), child er size choto
  // else child er size boro
  for (auto [d, cnt] : nodes[u].mp) {
    int actual_d = d + nodes[u].add + (swapped ? +1 : -1);
    nodes[v].mp[actual_d - nodes[v].add] += cnt;
  }
  nodes[v].add += !swapped;

  par[u] = v;
}

void dfs(int u, int p) {
  nodes[u].mp[0] = 1;
  nodes[u].add = 0;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    par[i] = i;
  }
  par[1] = 1;
  dfs(1, 0);

  cout << ans << '\n';

  return 0;
}