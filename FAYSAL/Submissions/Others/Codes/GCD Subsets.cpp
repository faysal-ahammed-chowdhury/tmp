#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 1e9 + 7;
vector<int> divs[N];
int cnt[N], f[N], g[N];

void sieve() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (auto d : divs[a[i]]) {
      cnt[d]++;
    }
  }

  for (int d = 1; d <= n; d++) {
    f[d] = power(2, cnt[d], mod) - 1;
    if (f[d] < 0) f[d] += mod;

    // cout << d << ' ' << f[d] << '\n';
  }

  for (int i = n; i >= 1; i--) {
    g[i] = f[i];
    for (int j = i + i; j <= n; j += i) {
      g[i] -= g[j];
      if (g[i] < 0) g[i] += mod;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << g[i] << ' ';
  }
  cout << '\n';

  return 0;
}