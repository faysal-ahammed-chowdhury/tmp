#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2005;
int n, h, a[N];
int dp[N][N];

int f(int st, int en, int mid) {
  int mx = a[mid];
  int ans = 0;
  if (dp[mid][en] != -1) {
    ans += dp[mid][en];
  }
  else {
    int cur = 0;
    for (int i = mid; i <= en; i++) {
      mx = max(mx, a[i]);
      cur += h - mx;
      dp[mid][i] = cur;
    }
    ans += cur;
  }

  mx = a[mid];
  if (mid > st and dp[mid][st] != -1) {
    ans += dp[mid][st];
  }
  else {
    int cur = 0;
    for (int i = mid - 1; i >= st; i--) {
      mx = max(mx, a[i]);
      cur += h - mx;
      dp[mid][i] = cur;
    }
    ans += cur;
  }
  return ans;
}

void solve() {
  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
      dp[0][j] = -1;
    }
  }

  // cout << f(1, n, 3) << '\n';
  // cout << dp[3][1] << '\n';
  // return;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f(1, n, i));

    int cur1 = 0;
    for (int j = i; j <= n; j++) {
      cur1 = max(cur1, f(i, n, j));
    }
    int cur2 = 0;
    for (int j = i - 1; j >= 1; j--) {
      cur2 = max(cur2, f(1, i - 1, j));
    }
    ans = max(ans, cur1 + cur2);

    cur1 = 0;
    for (int j = i + 1; j <= n; j++) {
      cur1 = max(cur1, f(i + 1, n, j));
    }
    cur2 = 0;
    for (int j = i; j >= 1; j--) {
      cur2 = max(cur2, f(1, i, j));
    }
    ans = max(ans, cur1 + cur2);

    // cout << i << ' ' << ans << '\n';
  }

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