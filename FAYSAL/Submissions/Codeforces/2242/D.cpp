#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N =  5e3 + 9, inf = 1e18;
int pref1[N], pref2[N];
int n, m;
map<int, vector<int>> mp;
int dp[N][N];

int f(int i, int last) {
  if (i <= 0) return 0;

  int &ans = dp[i][last];
  if (ans != -1) return ans;

  int x = pref1[i];
  ans = f(i - 1, last);
  auto it = lower_bound(mp[x].begin(), mp[x].end(), last);
  if (it != mp[x].begin()) {
    --it;
    ans = max(ans, 1 + f(i - 1, *it));
  }

  return ans;
}

void solve() {
  mp.clear();
  string s, t; cin >> s >> t;
  n = s.size(), m = t.size();
  s  = '.' + s, t = '.' + t;

  pref1[0] = 0, pref2[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref1[i] = (pref1[i - 1] + (s[i] - '0')) % 10;
  }
  for (int i = 1; i <= m; i++) {
    pref2[i] = (pref2[i - 1] + (t[i] - '0')) % 10;
    mp[pref2[i]].push_back(i);
  }

  if (pref1[n] != pref2[m]) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m + 1; j++) {
      dp[i][j] = -1;
    }
  }

  cout << f(n, m + 1) << '\n';
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