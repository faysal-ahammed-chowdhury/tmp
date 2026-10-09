#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 55;
int dp[N][N][N];

int f(int baki, int i, int mx) {
  if (baki == 0) return i == 0;
  if (i == 0) return 0;

  int &ans = dp[baki][i][mx];
  if (ans != -1) return ans;

  ans = 0;
  for (int j = 1; j <= min(mx, baki); j++) {
    ans += f(baki - j, i - 1, mx);
  }

  return ans;
}

int cs;
void solve() {
  int n, k, m; cin >> n >> k >> m;
  cout << "Case " << ++cs << ": ";
  cout << f(n, k, m) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}