#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5020, K = 15;
const ll inf = 1e18;
int n, k, x, a[N];
ll dp[N][N], tree[N][K];
ll tmp[N];

// ll f(int i, int taken) {
//   // cout << i << ' ' << taken << '\n';
//   if (i > n) return taken == x + 1 ? 0 : -inf;

//   ll &ans = dp[i][taken];
//   if (ans != -1) return ans;

//   ans = -inf;
//   for (int j = 1; j <= k; j++) {
//     ans = max(ans, a[i] + f(i + j, taken + 1));
//   }

//   return ans;
// }

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = tmp[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = max(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

ll query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  // memset(dp, -1, sizeof dp);
  // ll ans = f(0, 0);
  // cout << (ans <= 0 ? -1 : ans) << '\n';

  for (int taken = x + 1; taken >= 0; taken--) {
    for (int i = n + 1; i >= 0; i--) {
      if (i == n + 1) {
        if (taken == x + 1) dp[i][taken] = 0;
        else dp[i][taken] = -inf;
        continue;
      }

      ll &ans = dp[i][taken];
      ans = -inf;
      if (taken > x) continue;
      // for (int j = 1; j <= k; j++) {
      //   if (i + j <= n + 1) {
      //     ans = max(ans, a[i] + dp[i + j][taken + 1]);
      //   }
      // }
      int to = min(i + k, n + 1);
      // ans = a[i] + st.query(1, 0, n + 1, i + 1, to);
      ans = a[i] + query(i + 2, to + 1);
    }

    for (int i = 0; i <= n + 1; i++) {
      // st.upd(1, 0, n + 1, i, dp[i][taken]);
      tmp[i + 1] = dp[i][taken];
    }


    build(n + 2);
  }

  ll ans = dp[0][0];
  cout << (ans <= 0 ? -1 : ans) << '\n';

  return 0;
}