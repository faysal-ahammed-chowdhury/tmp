#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9, K = 105, inf = 1e9;
int n, k, a[N], nxt[N];
int dp[N][2][2];

// int f(int i, int rem, bool is_starting_idx) {
//   if (i > n) return rem == 0 ? 0 : -inf;

//   int &ans = dp[i][rem][is_starting_idx];
//   if (ans != -1) return ans;

//   int r = nxt[i];
//   if (is_starting_idx) ans = is_starting_idx + f(r, rem, true);
//   ans = max(ans, is_starting_idx + f(i + 1, rem, false));
//   if (rem) ans = max(ans, is_starting_idx + f(i + 1, rem - 1, true));

//   return ans;
// }

void solve() {
  cin >> n >> k;
  k--;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  stack<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() and st.top().first < a[i]) {
      nxt[st.top().second] = i;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    nxt[st.top().second] = n + 1;
    st.pop();
  }

  // memset(dp, -1, sizeof dp);
  // cout << f(1, k, true) << '\n';

  for (int i = n + 1; i >= 1; i--) {
    for (int is_starting_idx = 0; is_starting_idx <= 1; is_starting_idx++) {
      dp[i][0][is_starting_idx] = -inf;
      dp[i][1][is_starting_idx] = -inf;
    }
  }

  for (int rem = 0; rem <= k; rem++) {
    for (int i = n + 1; i >= 1; i--) {
      for (int is_starting_idx = 0; is_starting_idx <= 1; is_starting_idx++) {
        if (i > n) {
          dp[i][0][is_starting_idx] = rem == 0 ? 0 : -inf;
          continue;
        }

        int &ans = dp[i][0][is_starting_idx];
        int r = nxt[i];
        if (is_starting_idx) ans = is_starting_idx + dp[r][0][true];
        ans = max(ans, is_starting_idx + dp[i + 1][0][false]);
        if (rem) ans = max(ans, is_starting_idx + dp[i + 1][1][true]);
      }
    }

    for (int i = n + 1; i >= 1; i--) {
      for (int is_starting_idx = 0; is_starting_idx <= 1; is_starting_idx++) {
        dp[i][1][is_starting_idx] = dp[i][0][is_starting_idx];
      }
    }
  }

  cout << dp[1][0][true] << '\n';
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