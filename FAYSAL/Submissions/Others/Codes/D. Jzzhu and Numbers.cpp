#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 1e6 + 9, MAX = (1 << 20), K = 21, mod = 1000000007;
int n, freq[MAX], dp[MAX][2];

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

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  for (int bit = 0; bit < K; bit++) {
    for (int x = MAX - 1; x >= 0; x--) {
      if (bit == 0) {
        dp[x][Mod(bit)] = freq[x];
        continue;
      }
      int &ans = dp[x][Mod(bit)];
      ans = dp[x][Mod(bit - 1)];
      if (!CHECK(x, bit - 1)) {
        int y = x;
        SET(y, bit - 1);
        if (y < MAX) {
          ans += dp[y][Mod(bit - 1)];
          ans %= mod;
        }
      }
    }
  }

  int ans = 0;
  for (int x = 0; x < MAX; x++) {
    int pop = __builtin_popcount(x);
    int mul = 1;
    if (pop & 1) mul = -1;
    if (mul < 0) mul += mod;

    ans = (ans + (1ll * mul * power(2, dp[x][Mod(K - 1)], mod) % mod)) % mod;
  }

  cout << ans << '\n';

  return 0;
}