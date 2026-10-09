#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 505;
string s, t;
int n, m;

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

short mx[N][N][N];

int dp[N][N];
const int inf = 1e18;
Hashing h1, h2;

int f(int i, int j) {
  if (i > n) return inf;

  int &ans = dp[i][j];
  if (ans != -1) return ans;

  ans = inf;
  ans = min(ans, (i == 1) + f(i + 1, j));

  for (int k = i; k <= n; k++) {
    int len = k - i + 1;
    if (i == 1) {
      if ((j + 1) + len - 1 <= m) {
        if (h1.get_hash(i, k) == h2.get_hash(j + 1, (j + 1) + len - 1)) {
          int x = (k < n) ? 1 : 0;
          ans = min(ans, x + len + (k == n ? 0 : f(k + 1, (j + 1) + len - 1)));
        }
        else {
          int x = (k < n) ? 1 : 0;
          ans = min(ans, len + x);
        }
      }
      else {
        int x = (k < n) ? 1 : 0;
        ans = min(ans, len + x);
      }
    }
    else {
      if (mx[i][k][j] == -1) {
        int x = (k < n) ? 1 : 0;
        ans = min(ans, len + x);
      }
      else {
        if (k < n) {
          ans = min(ans, len + 1 + f(k + 1, mx[i][k][j] + len - 1));
        }
        else {
          int en = m;
          int st = en - len + 1;
          if (h1.get_hash(i, k) == h2.get_hash(st, en) and st > j) {
            ans = min(ans, inf);
          }
          else {
            ans = min(ans, len);
          }
        }
      }
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  cin >> n >> m;
  cin >> s >> t;
  h1 = Hashing(s);
  h2 = Hashing(t);
  s = '.' + s;
  t = '.' + t;

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int len = j - i + 1;
      int last = -1;
      for (int k = m; k >= 1; k--) {
        mx[i][j][k] = last;
        if (k + len - 1 > m) continue;
        if (h1.get_hash(i, j) == h2.get_hash(k, k + len - 1)) {
          last = k;
        }
      }
      mx[i][j][0] = last;
    }
  }

  memset(dp, -1, sizeof dp);
  cout << f(1, 0) << '\n';
  // cout << min(n, f(1, 0)) << '\n';

  return 0;
}