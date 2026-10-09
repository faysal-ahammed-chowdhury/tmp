#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 65;
string s1, s2;
int sz;
ll dp[N][2];

ll f(int i, bool is_small) {
  if (i == sz) return 0;
  int l = s1[i] - '0', r = s2[i] - '0';
  if (is_small) r = 1;

  ll &ans = dp[i][is_small];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    ans = max(ans, (x == 1) + f(i + 1, (is_small | (x < r))));
  }
  return ans;
}

ll print(int i, bool is_small) {
  if (i == sz) return 0;
  int l = s1[i] - '0', r = s2[i] - '0';
  if (is_small) r = 1;

  int bit = sz - 1 - i;
  ll ans = f(i, is_small);

  ll ret = 0;
  for (int x = l; x <= r; x++) {
    if (ans == (x == 1) + f(i + 1, (is_small | (x < r)))) {
      if (x) ret = (1ll << bit);
      ret += print(i + 1, (is_small | (x < r)));
      break;
    }
  }

  return ret;
}

void get(ll l, ll r) {
  bitset<62> bs(l);
  s1 = bs.to_string();
  bitset<62> bs2(r);
  s2 = bs2.to_string();
  sz = s1.size();
  memset(dp, -1, sizeof(dp));
}

void solve() {
  ll l, r; cin >> l >> r;
  get(l, r);
  ll ans = f(0, false);

  // cout << ans << '\n';
  cout << print(0, false) << '\n';
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