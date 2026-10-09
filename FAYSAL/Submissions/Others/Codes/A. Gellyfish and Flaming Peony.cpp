#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 5005, inf = 1e9;
int n, a[N], dp[N][N];
int req_gc;

int f(int i, int gc) {
  if (i > n) return gc == req_gc ? 0 : inf;

  int &ans = dp[i][gc];
  if (ans != -1) return ans;

  ans = f(i + 1, gc);
  ans = min(ans, 1 + f(i + 1, __gcd(gc, a[i])));

  return ans;
}

void solve() {
  cin >> n;
  req_gc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    req_gc = __gcd(req_gc, a[i]);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 5000; j++) {
      dp[i][j] = -1;
    }
  }

  int need = f(1, 0);
  if (need == 1) {
    int ans = n;
    for (int i = 1; i <= n; i++) {
      if (a[i] == req_gc) ans--;
    }

    cout << ans << '\n';
    return;
  }

  int ans = need + n - 2;
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