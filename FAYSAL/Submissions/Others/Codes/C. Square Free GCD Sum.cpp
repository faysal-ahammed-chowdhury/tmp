#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int MAX = (1 << 20), mod = 1e9 + 7;
vector<int> primes;
int n, m, cnt[MAX], f[MAX];
int dp[2][MAX];

int Mod(int x) {
  x %= 2;
  if (x < 0) x += 2;
  return x;
}

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    primes.push_back(x);
  }
  sort(primes.begin(), primes.end());
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int mask = 0;
    for (int j = 0; j < m; j++) {
      if (x % primes[j] == 0) mask |= (1 << j);
    }
    cnt[mask]++;
    // cout << mask << '\n';
  }

  for (int bit = 0; bit <= m; bit++) {
    for (int mask = 0; mask < MAX; mask++) {
      if (bit == 0) {
        dp[Mod(bit)][mask] = cnt[mask];
        continue;
      }
      int &ans = dp[Mod(bit)][mask];
      ans = dp[Mod(bit - 1)][mask];
      if (!CHECK(mask, bit - 1)) {
        int y = mask;
        SET(y, bit - 1);
        ans += dp[Mod(bit - 1)][y];
        ans %= mod;
      }
      if (bit == m) {
        f[mask] =  power(2, ans, mod) - 1;
        if (f[mask] < 0) f[mask] += mod;
        // cout << mask << ' ' << f[mask] << '\n';
      }
    }
  }

  for (int bit = 0; bit < m; bit++) {
    for (int mask = 0; mask < MAX; mask++) {
      if (!(mask & (1 << bit))) {
        f[mask] -= f[mask | (1 << bit)];
        if (f[mask] < 0) f[mask] += mod;
      }
    }
  }

  int ans = 0;
  for (int mask = 0; mask < MAX; mask++) {
        // cout << mask << ' ' << f[mask] << '\n';
    int prime = 1;
    for (int bit = 0; bit < m; bit++) {
      if (CHECK(mask, bit)) {
        prime = prime * primes[bit];
      }
    }
    // cout << f[mask] << '\n';
    ans += 1ll * f[mask] * prime % mod;
    ans %= mod;
  }

  cout << ans << '\n';

  return 0;
}