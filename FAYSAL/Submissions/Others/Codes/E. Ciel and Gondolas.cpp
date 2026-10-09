#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4005, inf = 1e9;
int n, k, a[N][N], cost[N][N], row_pref[N][N];
int dp[N], ndp[N];

void solveDnC(int l, int r, int L, int R) {
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

  if (l <= mid - 1) solveDnC(l, mid - 1, L, opt);
  if (mid + 1 <= r) solveDnC(mid + 1, r, opt, R);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n  >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >>  a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      row_pref[i][j] = row_pref[i][j - 1] + a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    int old = 0;
    for (int j = i; j <= n; j++) {
      int cur = row_pref[j][j] - row_pref[j][i - 1];
      cost[i][j] = old + cur;
      old += cur;
    }
  }

  for (int j = 0; j <= n; j++) {
    dp[j] = inf;
  }
  dp[0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      ndp[j] = inf;
    }
    solveDnC(1, n, 1, n);
    swap(dp, ndp);
  }

  cout << dp[n] << '\n';

  return 0;
}