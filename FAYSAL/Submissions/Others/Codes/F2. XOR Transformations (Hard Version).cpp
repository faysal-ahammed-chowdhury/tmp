#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

const int N =  1e5 + 9, inf = (1 << 30) - 1;
int n, a[N], b[N], dp[32];

struct Trie {
  static const int K = 30; // bit size
  struct TrieNode {
    TrieNode *nxt[2]; // 0, 1
    int cnt;
    TrieNode() {
      nxt[0] = NULL, nxt[1] = NULL;
      cnt = 0;
    }
  } *root;
  Trie() {
    root = new TrieNode();
  }
  void insert(int x) {
    TrieNode *cur = root;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[k] == NULL) cur -> nxt[k] = new TrieNode();
      cur = cur -> nxt[k];
      cur -> cnt++;
    }
  }
  void rem(TrieNode *cur, int x, int pos) { // free :: De Alloactes Memory
    if (pos < 0) return;
    int k = (x >> pos) & 1; // pos'th bit
    rem(cur -> nxt[k], x, pos - 1);
    cur -> nxt[k] -> cnt--;
    if (cur -> nxt[k] -> cnt == 0) {
      free(cur -> nxt[k]);
      cur -> nxt[k] = NULL;
    }
  }
  int query(int x, int k) { // number of values s.t. val ^ x < k
    TrieNode* cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      if (cur == NULL) break;
      int b1 = x >> i & 1, b2 = k >> i & 1;
      if (b2 == 1) {
        if (cur -> nxt[b1]) ans += cur -> nxt[b1] -> cnt;
        cur = cur -> nxt[!b1];
      } else cur = cur -> nxt[b1];
    }
    return ans;
  }
  int query_kth(int x, int k) { // kth element of val ^ x
    TrieNode* cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      if (cur == NULL) break;
      int b1 = x >> i & 1;
      if (cur -> nxt[b1] and cur -> nxt[b1] -> cnt >= k) {
        cur = cur -> nxt[b1];
      }
      else if (cur -> nxt[!b1]) {
        ans |= (1 << i);
        k -= cur -> nxt[b1] ? cur -> nxt[b1] -> cnt : 0;
        cur = cur -> nxt[!b1];
      }
      else return -1;
    }
    return ans;
  }
  int get_max(int x) { // returns maximum of val ^ x
    TrieNode *cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[!k] != NULL) {
        ans += (1 << i);
        cur = cur -> nxt[!k];
      }
      else {
        cur = cur -> nxt[k];
      }
    }
    return ans;
  }
  int get_min(int x) { // returns minimum of val ^ x
    TrieNode *cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[k] != NULL) {
        cur = cur -> nxt[k];
      }
      else {
        ans += (1 << i);
        cur = cur -> nxt[!k];
      }
    }
    return ans;
  }
  void del(TrieNode* cur) {
    for (int i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
  }
};


void f() {
  Trie tr;
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  for (int i = 1; i <= n; i++) {
    tr.insert(a[i]);
  }

  for (int i = 1; i <= n; i++) {
    pq.push({tr.query_kth(a[i], 2), i, 2});
    // cout << tr.query_kth(a[i], 2) << '\n';
  }

  int idx = 0;
  for (int i = 1; i <= 2 * n; i++) {
    auto [x, id, k] = pq.top(); pq.pop();
    if (i % 2 == 0) b[++idx] = x;
    if (k + 1 <= n) {
      pq.push({tr.query_kth(a[id], k + 1), id, k + 1});
    }
  }

  for (int i = 1; i <= n; i++) {
    a[i] = b[i];
  }

  tr.del(tr.root);
}

void solve() {
  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  for (int x = 0; x <= 30; x++) {
    if (x == 0) {
      dp[x] = a[n] - a[1];
      continue;
    }
    if (a[n] != 0) f();
    dp[x] = a[n] - a[1];
  }

  while (q--) {
    int x; cin >> x;
    if (x > 30) {
      cout << 0 << '\n';
      continue;
    }
    cout << dp[x] << '\n';
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