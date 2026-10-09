#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9, mod = 998244353;
vector<int> divs[N];
int spf[N], phi[N];
int cnt[N];

void sieve() {
  divs[1].push_back(1);
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    divs[i].push_back(1);
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
      if (spf[i] == i) {
        spf[j] = min(spf[j], i);
      }
    }
  }

  for (int i = 2; i < N; i++) {
    int x = i, res = 1;
    while (x > 1) {
      int p = spf[x], pw = 1;
      while (x % p == 0) {
        pw *= p;
        x /= spf[x];
      }
      res *= pw - (pw / p); // (p^e) - (p^(e-1))
    }
    phi[i] = res;
  }
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

int nC2(int n) {
  ll x = (1ll * n * (n - 1)) / 2;
  return (x % mod);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (auto d : divs[x]) {
      cnt[d]++;
    }
  }

  int sum = 0;
  for (int d = 1; d < N; d++) {
    sum += 1ll * phi[d] * nC2(cnt[d]) % mod;
    sum %= mod;
  }

  int sz = n;
  int q; cin >> q;
  while (q--) {
    int type, x; cin >> type >> x;
    if (type == 1) {
      for (auto d : divs[x]) {
        sum -= 1ll * phi[d] * nC2(cnt[d]) % mod;
        if (sum < 0) sum += mod;
        cnt[d]++;
        sum += 1ll * phi[d] * nC2(cnt[d]) % mod;
        sum %= mod;
      }
      sz++;

      int ans = 1ll * sum * power(nC2(sz), mod - 2, mod) % mod;
      cout << ans << '\n';
    }
    else {
      for (auto d : divs[x]) {
        sum -= 1ll * phi[d] * nC2(cnt[d]) % mod;
        if (sum < 0) sum += mod;
        cnt[d]--;
        sum += 1ll * phi[d] * nC2(cnt[d]) % mod;
        sum %= mod;
      }
      sz--;

      int ans = 1ll * sum * power(nC2(sz), mod - 2, mod) % mod;
      cout << ans << '\n';
    }
  }

  return 0;
}