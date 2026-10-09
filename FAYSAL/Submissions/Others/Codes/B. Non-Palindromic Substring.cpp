#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long

const int N = 2e5 + 9, K = 20;
short tree[N][K], tree2[N][K];
string s;

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = (i + 1 <= n and s[i] == s[i + 1]) or (i == n);
    tree2[i][0] = (i + 2 <= n and s[i] == s[i + 2])  or (i == n) or (i == n - 1);
    // cout << tree2[i][0] << '\n';
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
      tree2[i][k] = min(tree2[i][k - 1], tree2[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query2(int l, int r) {
  if (l > r) return 1;
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]);
}

int query3(int l, int r) {
  if (l > r) return 1;
  int k = log2_floor(r - l + 1);
  return min(tree2[l][k], tree2[r - (1 << k) + 1][k]);
}

ll get(int n) {
  return (1ll * n * (n + 1)) / 2;
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
  vector<pair<int, int>> rev_hash_val;
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
    rev_hash_val.emplace_back(0, 0);
    for (int i = 0, j = n - 1; i < n; i++, j--) {
      pair<int, int> p;
      p.first = (rev_hash_val[i].first + 1ll * s[i] * pw[j].first % MOD1) % MOD1;
      p.second = (rev_hash_val[i].second + 1ll * s[i] * pw[j].second % MOD2) % MOD2;
      rev_hash_val.push_back(p);
    }
  }

  pair<int, int> get_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> rev_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (rev_hash_val[r].first - rev_hash_val[l - 1].first + MOD1) * 1ll * ipw[n - r].first % MOD1;
    ans.second = (rev_hash_val[r].second - rev_hash_val[l - 1].second + MOD2) * 1ll * ipw[n - r].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
  bool is_palindrome(int l, int r) {
    return get_hash(l, r) == rev_hash(l, r);
  }
};

void solve() {
  int n, q; cin >> n >> q;
  cin >> s;
  Hashing hs(s);
  s = '.' + s;
  build(n);

  while (q--) {
    int l, r; cin >> l >> r;
    int len = r - l + 1;

    ll ans = 0;
    int ok2 = query2(l, r - 1) == 0;
    int ok3 = query3(l, r - 2) == 0;

    int odd = (len + 1) / 2;

    if (ok2) {
      ans += get(len) - (1ll * odd * odd);
      if (hs.is_palindrome(l, r) and !(len & 1)) ans -= len;
    }

    if (ok3) {
      ans += 1ll * odd * odd;
      ans--;
      if (hs.is_palindrome(l, r) and (len & 1) and len > 1) ans -= len;
    }

    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}