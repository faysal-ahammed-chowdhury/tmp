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

  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};

const int N = 1e6 + 9;
vector<int> g[N];
int dp[N][2];
bool vis[N];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dp[i][0] = dp[i][1] = 0;
    vis[i] = false;
  }
}

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277; // change here
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1ll * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1ll * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1ll * ipw[i - 1].second * ip2 % MOD2;
  }
}

struct Hashing {
  int n;
  string s;
  vector<pair<int, int>> hash_val;
  Hashing() {}
  Hashing(string _s) {
    s = _s;
    n = s.size();
    hash_val.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hash_val[i].first + 1ll * s[i] * pw[i].first % MOD1) % MOD1;
      p.second = (hash_val[i].second + 1ll * s[i] * pw[i].second % MOD2) % MOD2;
      hash_val.push_back(p);
    }
  }

  pair<int, int> get_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
};


void dfs(int u) {
  // cout << u << '\n';
  vis[u] = true;
  dp[u][1] = 1;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
      dp[u][0] += max(dp[v][0], dp[v][1]);
      dp[u][1] += dp[v][0];
    }
  }
}

void solve() {
  int n; cin >> n;
  string s[n + 1];
  vector<pair<int, int>> vec;
  Hashing hs[n + 1];
  int mx_len = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    reverse(s[i].begin(), s[i].end());
    vec.push_back({s[i].size(), i});
    mx_len = max(mx_len, (int)s[i].size());
    hs[i] = Hashing(s[i]);
  }

  sort(vec.rbegin(), vec.rend());

  gp_hash_table<pair<int, int>, int, custom_hash> mp;
  vector<pair<int, int>> new_vec;
  int here = 0;
  int id = 1;
  for (int len = mx_len; len >= 1; len--) {
    for (auto [my_len, idx] : vec) {
      if (len > my_len) break;

      int st = my_len - len + 1;
      auto my_hash = hs[idx].get_hash(st, my_len);
      if (mp.find(my_hash) != mp.end()) continue;
      mp[my_hash] = id++;
      here = max(mp[my_hash], here);

      new_vec.push_back({len, mp[my_hash]});

      for (char c = 'a'; c <= 'z'; c++) {
        auto cur_hash = my_hash;
        cur_hash.first = (cur_hash.first + (1ll * c * pw[len].first % MOD1)) % MOD1;
        cur_hash.second = (cur_hash.second + (1ll * c * pw[len].second % MOD2)) % MOD2;

        if (mp.find(cur_hash) != mp.end()) {
          g[mp[my_hash]].push_back(mp[cur_hash]);
          g[mp[cur_hash]].push_back(mp[my_hash]);
        }
      }
    }
  }

  sort(new_vec.begin(), new_vec.end());

  int ans = 0;
  for (auto [_, idx] : new_vec) {
    // cout << idx << '\n';
    if (!vis[idx]) {
      dfs(idx);
      ans += max(dp[idx][0], dp[idx][1]);
    }
  }

  cout << ans << '\n';


  clr(here);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}