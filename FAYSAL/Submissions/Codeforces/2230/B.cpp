#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
string s; 
int n;
int dp[N][6];

int f(int i, int last) {
  if (i > n) return 0;

  int &ans = dp[i][last];
  if (ans != -1) return ans;

  int x = s[i] - '0';
  int y = last * 10 + x;

  ans = 1e9;

  ans = min(ans, 1 + f(i + 1, last));
  if (y % 4 != 0 and x % 4 != 0) {
    ans = min(ans, f(i + 1, x));
  }

  return ans;
}

void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 4; j++) {
      dp[i][j] = -1;
    }
  }

  cout << f(1, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}