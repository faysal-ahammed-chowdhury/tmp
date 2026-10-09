#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int inf = 1e18;
int cost[3005][3005];

void solveDnC(int l, int r, int L, int R, vector<int> &dp, vector<int> &ndp) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int opt = L;
  for (int i = L; i <= R; i++) {
    if (i > mid) break;
    int cur = cost[i][mid] + dp[i - 1];
    if (cur <= ndp[mid]) {
      ndp[mid] = cur;
      opt = i;
    }
  }

  solveDnC(l, mid - 1, L, opt, dp, ndp);
  solveDnC(mid + 1, r, opt, R, dp, ndp);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1;  i <= n; i++) {
    int sum = 0;
    for (int j = i; j <= n; j++) {
      sum += a[j];
      cost[i][j] = sum * sum;
    }
  }

  vector<int> dp(n + 5, inf);
  dp[0] = 0;
  for (int i = 1; i <= k; i++) {
    vector<int> ndp(n + 5, inf);
    solveDnC(1, n, 1, n, dp, ndp);
    swap(dp, ndp);
  }

  cout << dp[n] << '\n';

  return 0;
}