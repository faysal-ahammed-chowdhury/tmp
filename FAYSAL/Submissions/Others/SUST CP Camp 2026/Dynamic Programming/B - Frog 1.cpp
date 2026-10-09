#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N], dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; i--) {
    if (i == n) {
      dp[i] = 0;
      continue;
    }
    dp[i] = 2e9;
    if (i + 1 <= n) dp[i] = min(dp[i], abs(a[i] - a[i + 1]) + dp[i + 1]);
    if (i + 2 <= n) dp[i] = min(dp[i], abs(a[i] - a[i + 2]) + dp[i + 2]);
  }

  cout << dp[1] << '\n';

  return 0;
}