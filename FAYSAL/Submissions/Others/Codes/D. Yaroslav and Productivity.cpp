#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, m;
int a[N];
bool allowed[N];
int dp[N][2];

int f(int i, int running) {
  if (i <= 0) return 0;

  int &ans = dp[i][running];
  if (ans != -1) return ans;

  ans = (running ? -a[i] : a[i]) + f(i - 1, running);
  if (allowed[i]) {
    int x;
    if (running) x = a[i];
    else x = -a[i];
    ans = max(ans, x + f(i - 1, running ^ 1));
  }

  return ans;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    allowed[i] = false;
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    allowed[x] = true;
  }

  cout << f(n, false) << '\n';
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