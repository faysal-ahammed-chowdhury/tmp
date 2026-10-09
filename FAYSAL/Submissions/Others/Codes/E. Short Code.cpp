#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int par[N];
vector<int> g[N];
bool is_end[N];

struct node {
  multiset<int> ms;
  int add;
} nodes[N];

const char base_char = 'a';  // change here
struct TrieNode {
  bool is_end;
  TrieNode * nxt[26];
  TrieNode() {
    is_end = false;
    for (int i = 0; i < 26; i++) nxt[i] = NULL;
  }
} *root;

void insert(const string &s) {
  TrieNode *cur = root;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    int idx = s[i] - base_char;
    if (cur -> nxt[idx] == NULL) cur -> nxt[idx] = new TrieNode();
    cur = cur -> nxt[idx];
  }
  cur -> is_end = true;
}
void del(TrieNode *cur) {
  for (int i = 0; i < 26; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
  delete(cur);
}

// converting trie to tree
int timer;
void f(TrieNode *u, int p) {
  ++timer;
  int x = timer;
  is_end[x] = u -> is_end;
  g[p].push_back(x);
  for (int v = 0; v < 26; v++) {
    if (u -> nxt[v]) {
      f(u -> nxt[v], x);
    }
  }
}

int find(int i) {
  return (i == par[i] ? i : par[i] = find(par[i]));
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  bool swapped = false;
  if (nodes[u].ms.size() >= nodes[v].ms.size()) {
    swap(u, v);
    swapped = true;
  }
  if (!swapped) nodes[v].add++;
  for (auto x : nodes[u].ms) {
    if (!swapped) {
      nodes[v].ms.insert((x + nodes[u].add) - nodes[v].add);
    }
    else {
      nodes[v].ms.insert(((x + nodes[u].add) + 1) - nodes[v].add);
    }
  }
  nodes[u].ms.clear();
  par[u] = v;
}


void dfs(int u, int p) {
  nodes[u].ms.insert(1);
  nodes[u].add = 0;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      merge(u, v);
    }
  }
  if (!is_end[u] and u != 1) {
    nodes[find(u)].ms.erase(--nodes[find(u)].ms.end());
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  root = new TrieNode(); // init new trie

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    insert(s);
  }

  f(root, 0);
  for (int i = 1; i <= timer; i++) {
    par[i] = i;
  }

  dfs(1, 0);
  int ans = 0;
  for (auto x : nodes[find(1)].ms) {
    ans += x + nodes[find(1)].add - 1;
  }
  cout << ans << '\n';

  del(root); // clear trie

  return 0;
}