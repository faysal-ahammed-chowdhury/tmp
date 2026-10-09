#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 12;
string s;
int sz, k;
int dp[N][2][100][100];

int f(int i, bool is_small, int rem, int digit_sum) {
  if (i == sz) return rem == 0 and (digit_sum % k) == 0;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 9;

  int &ans = dp[i][is_small][rem][digit_sum];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    ans += f(i + 1, (is_small | (x < r)), ((rem * 10) + x) % k, digit_sum + x);
  }
  return ans;
}

void get(long long x) {
  s = to_string(x);
  sz = s.size();
  memset(dp, -1, sizeof(dp));
}

int cs;
void solve() {
  int a, b; cin >> a >> b >> k;
  if (k > 100) {
    cout << "Case " << ++cs << ": 0\n";
    return;
  }
  get(b);
  int ans = f(0, false, 0, 0);
  get(a - 1);
  ans -= f(0, false, 0, 0);

  cout << "Case " << ++cs << ": " << ans << '\n';
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