#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9, mod = 1e9 + 7;
int spf[N];

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void solve() {
  int n, x; cin >> n >> x;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    while (x > 1) {
      int p = spf[x];
      int pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      mp[p] += pw;
    }
  }

  int ans = 1;
  for (auto [p, pw] : mp) {
    ans = 1ll * ans * (pw + 1) % mod;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}