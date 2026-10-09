#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define GYM 0
#define CONTEST 1
#define REST 2

const int N = 105;
int n, a[N], dp[N][5];

int f(int i, int last) {
  if (i > n) return 0;

  int &ans = dp[i][last];
  if (ans != -1) return ans;

  ans = 1 + f(i + 1, REST);
  if (a[i] >= 2 and last != GYM) ans = min(ans, f(i + 1, GYM));
  if ((a[i] == 1 or a[i] == 3) and last != CONTEST) ans = min(ans, f(i + 1, CONTEST));

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  cout << f(1, REST) << '\n';

  return 0;
}