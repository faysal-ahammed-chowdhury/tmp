#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 55, mod = 1e9 + 7;
string s;
int sz;
int dp[N][N][N][N][2];

int f(int i, int rem1, int rem2, int m, bool has_started) {
  if (i == 0) return rem1 == 0 and rem2 == 0 and has_started;
  int l = 0, r = 9;

  int &ans = dp[i][rem1][rem2][m][has_started];
  if (ans != -1) return ans;

  ans = 0;
  for (int x = l; x <= r; x++) {
    bool new_has_started = has_started | (x != 0);
    ans += f(i - 1, ((1ll * rem1 * 10 % mod) + x) % m, (rem2 + x) % m, m, new_has_started);
    ans %= mod;
  }
  return ans;
}

int solve(string &tmp, int m) {
  s = tmp;
  int sz = s.size();

  int rem1 = 0, rem2 = 0;
  int ans = 0;
  for (int i = 0; i < sz; i++) {
    for (int x = 0; x < (s[i] - '0'); x++) {
      int baki = sz - (i + 1);
      bool has_started = (i > 0) ? true : (x > 0) ? true : false;
      ans += f(baki, ((1ll * rem1 * 10 % mod) + x) % m, (rem2 + x) % m, m, has_started);
      ans %= mod;

      // cout << i << ' ' << x << ' ' << rem1 << ' ' << rem2 << '\n';
    }

    rem1 = ((1ll * rem1 * 10 % mod) + (s[i] - '0')) % m;
    rem2 = (rem2 + (s[i] - '0')) % m;
  }

  if (rem1 == 0 and rem2 == 0) {
    ans++;
    if (ans >= mod) ans %= mod;
  }

  return ans;
}

int cs;
void solve() {
  int m;
  string s1, s2; cin >> s1 >> s2 >> m;
  int ans1 = solve(s2, m);
  int ans2 = solve(s1, m);
  // int ans2 = 0;

  int ans = ans1 - ans2;
  if (ans < 0) ans += mod;

  int rem1 = 0, rem2 = 0;
  for (auto c : s1) {
    rem1 = ((1ll * rem1 * 10 % mod) + (c - '0')) % m;
    rem2 = (rem2 + (c - '0')) % m;
  }

  if (rem1 == 0 and rem2 == 0) {
    ans++;
    if (ans >= mod) ans %= mod;
  }

  // cout << ans1 << ' ' << ans2 << ' ';
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}