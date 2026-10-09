#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4005;
int dp[N];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b, c; cin >> n >> a >> b >> c;
  for (int len = 0; len <= n; len++) {
    if (len == 0) {
      dp[len] = 0;
      continue;
    }

    dp[len] = -1e9;
    if (len - a >= 0) dp[len] = max(dp[len], 1 + dp[len - a]);
    if (len - b >= 0) dp[len] = max(dp[len], 1 + dp[len - b]);
    if (len - c >= 0) dp[len] = max(dp[len], 1 + dp[len - c]);
  }

  cout << dp[n] << '\n';

  return 0;
}