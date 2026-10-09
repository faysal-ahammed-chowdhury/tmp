#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

const int N = 1e6 + 100, mod = 100000007;
int fact[N], ifact[N];

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

int nCr(int n, int r) {
  if (r > n) return 0;
  if (r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int nPr(int n, int r) {
  if (r > n) return 0;
  if (r < 0) return 0;
  return 1ll * fact[n] * ifact[n - r] % mod;
}

int stars_and_bars(int n, int k) {
  return nCr(n + k - 1, n);
}

int cs;
void solve() {
  int k, n; cin >> k >> n;
  int a[k], b[k];
  for (int i = 0; i < k; i++) {
    cin >> a[i] >> b[i];
  }

  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }

  int ans = 0;

  for (int mask = 0; mask < (1ll << k); mask++) {
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
      if (CHECK(mask, i)) {
        cnt++;
        sum += b[i] + 1;
      }
      else {
        sum += a[i];
      }
    }

    // cout << cnt << ' ' << sum << ' ' << stars_and_bars(n - sum, k) << '\n';

    if (cnt & 1) {
      ans -= stars_and_bars(n - sum, k);
      if (ans >= mod) ans -= mod;
    }
    else {
      ans += stars_and_bars(n - sum, k);
      if (ans < 0) ans += mod;
    }
  }

  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}