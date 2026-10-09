#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 998244353;
int fact[N];
int pref[N];

void prec() {
  fact[1] = 1;
  for (int i = 2; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << 0 << '\n';
    return;
  }

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = (pref[i - 1] + a[i]) % mod;
  }

  int ans = (a[1] - a[2]) % mod;
  for (int i = 3; i <= n; i++) {
    int here = 1ll * a[i] * (i - 1) % mod;
    here = pref[i - 1] - here;
    if (here < 0) here += mod;

    ans = 1ll * ans * (i - 1) % mod;
    ans += 1ll * here * fact[i - 2] % mod;
    ans %= mod;
  }

  cout << ans << '\n';
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