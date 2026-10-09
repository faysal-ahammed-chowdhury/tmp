#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;

void solveDnC(vector<int> &v, int l, int r, int L, int R, vector<int> &dp, vector<int> &ndp, int A, vector<int> &satisfaction) {
  if (l > r) return;
  int sz = (r - l + 1) / 2;
  int mid = (sz / 2) + l;
  int k = v[mid];
  int opt = L;
  for (int i = L; i <= R; i++) {
    int last = v[i];
    if (last > k) break;
    int x = (k - last) / A;
    int cur = satisfaction[x] + dp[k - x * A];
    if (cur >= ndp[k]) {
      ndp[k] = cur;
      opt = i;
    }
  }


  solveDnC(v, l, mid - 1, L, opt, dp, ndp, A, satisfaction);
  solveDnC(v, mid + 1, r, opt, R, dp, ndp, A, satisfaction);
}

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  vector<int> dp(k + 5, -inf);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > k) continue;
    vector<int> satisfaction;
    int cur = 0;
    for (int x = 0; x <= k; x++) {
      if (x == 0) satisfaction.push_back(0);
      else {
        cur += b[i] / x;
        satisfaction.push_back(cur);
      }
    }

    vector<vector<int>> vec(a[i]);
    for (int j = 0; j <= k; j++) {
      int idx = j % a[i];
      vec[idx].push_back(j);
    }

    vector<int> ndp(k + 5, -inf);
    for (auto v : vec) {
      solveDnC(v, 0, v.size() - 1, 0, v.size() - 1, dp, ndp, a[i], satisfaction);
    }

    swap(dp, ndp);
  }

  int ans = *max_element(dp.begin(), dp.end());
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