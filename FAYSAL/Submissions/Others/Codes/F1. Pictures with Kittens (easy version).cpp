#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 205;
const ll inf = 1e18;
int n, k, x, a[N];
ll dp[N][N][N];

ll f(int i, int last, int taken) {
  // cout << i << ' ' << last << ' ' << taken << '\n';
  if (i - last > k) return -inf;
  if (i > n) return taken == x ? 0 : -inf;

  ll &ans = dp[i][last][taken];
  if (ans != -1) return ans;

  ans = f(i + 1, last, taken);
  if (taken < x) {
    ans = max(ans, a[i] + f(i + 1, i, taken + 1));
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  ll ans = f(1, 0, 0);
  cout << (ans <= 0 ? -1 : ans) << '\n';

  return 0;
}