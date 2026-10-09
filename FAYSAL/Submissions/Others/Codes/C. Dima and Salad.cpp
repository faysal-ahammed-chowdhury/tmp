#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105, inf = 1e9;
int n, k, a[N], b[N], dp[N][(int)2e5 + 9];

int f(int i, int diff) {
  if (i > n) return diff == 0 ? 0 : -inf;

  int &ans = dp[i][diff + (int)1e5];
  if (ans != -1) return ans;

  ans = f(i + 1, diff);
  ans = max(ans, a[i] + f(i + 1, diff + a[i] - b[i]));

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] *= k;
  }

  memset(dp, -1, sizeof dp);
  int ans = f(1, 0);
  cout << (ans <= 0 ? -1 : ans) << '\n';

  return 0;
}