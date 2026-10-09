#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, dp[N];
string s[3];

int f(int i) {
  if (i > n) return 0;

  int &ans = dp[i];
  if (ans != -1) return ans;

  ans = (s[1][i] != s[2][i]) + f(i + 1);
  if (i + 1 <= n) {
    int cost = (s[1][i] != s[1][i + 1]);
    cost += (s[2][i] != s[2][i + 1]);
    ans = min(ans, cost + f(i + 2));
  }

  return ans;
}

void solve() {
  cin >> n >> s[1] >> s[2];
  s[1] = '.' + s[1];
  s[2] = '.' + s[2];

  for (int i = 1; i <= n; i++) {
    dp[i] = -1;
  }

  cout << f(1) << '\n';
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