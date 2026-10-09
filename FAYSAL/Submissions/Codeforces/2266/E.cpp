#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5 + 9, inf = 1e18;
int spf[N], freq[N];
int n, k;
int dp[N];

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

int f(int x) {
  if (x <= k) return 0;

  int &ans = dp[x];
  if (ans != -1) return ans;

  ans = inf;
  int tmp = x;
  while (tmp > 1) {
    int p = spf[tmp];
    int nwx = x / p;
    // cout << nwx << '\n';
    ans = min(ans, 1 + (p * f(nwx)));
    while (tmp % p == 0) {
      tmp /= p;
    }
  }

  return ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    freq[i] = 0;
    dp[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (freq[i] == 0) continue;
    ans += freq[i] * f(i);
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