#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 3e5 + 9, inf = 1e9;
int n;
string s;
int dp[N][20];

int f(int i, int sum) {
  if (sum > 9) return inf;
  if (sum < -9) return inf;
  if (i > n) return 0;

  int &ans = dp[i][sum + 10];
  if (ans != -1) return ans;

  ans = inf;
  for (int x = 1; x <= 3; x++) {
    if (s[i] == '0' and sum + x == 0) {
      ans = min(ans, max(abs(x), f(i + 1, sum + x)));
    }
    if (s[i] == '+' and sum + x > 0) {
      ans = min(ans, max(abs(x), f(i + 1, sum + x)));
    }
    if (s[i] == '-' and sum + x < 0) {
      ans = min(ans, max(abs(x), f(i + 1, sum + x)));
    }

    int y = -x;
    if (s[i] == '0' and sum + y == 0) {
      ans = min(ans, max(abs(x), f(i + 1, sum + y)));
    }
    if (s[i] == '+' and sum + y > 0) {
      ans = min(ans, max(abs(x), f(i + 1, sum + y)));
    }
    if (s[i] == '-' and sum + y < 0) {
      ans = min(ans, max(abs(x), f(i + 1, sum + y)));
    }
  }

  return ans;
}

void solve() {
  cin >> n >> s;
  s = '0' + s;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 20; j++) {
      dp[i][j] = -1;
    }
  }
  // memset(dp, -1, sizeof dp);

  int ans = f(1, 0);
  if (ans >= inf) ans = -1;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}