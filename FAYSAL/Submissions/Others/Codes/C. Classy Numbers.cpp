#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 21;
string s;
int sz;
ll dp[N][2][4];

ll f(int i, bool is_small, int cnt) {
  if (i == sz) return 1;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 9;

  ll &ans = dp[i][is_small][cnt];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    int new_cnt = cnt + (x > 0);
    if (new_cnt <= 3) ans += f(i + 1, (is_small | (x < r)), new_cnt);
  }
  return ans;
}

void get(long long x) {
  if (x < 0) return;
  s = "";
  while (x > 0) {
    char c = (x % 10) + '0';
    s += c;
    x /= 10;
  }
  reverse(s.begin(), s.end());
  sz = s.size();
  memset(dp, -1, sizeof(dp));
}

void solve() {
  ll l, r; cin >> l >> r;
  get(r);
  ll ans = f(0, false, 0);
  get(l - 1);
  ans -= f(0, false, 0);
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