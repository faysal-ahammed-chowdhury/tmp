#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005, mod = 998244353;
int n, k;
string s;
int dp[N];

vector<int> build_lps(string &pat) {
  int n = pat.size();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];
    while (j > 0 and pat[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (pat[i] == pat[j]) j++;
    lps[i] = j;
  }
  return lps;
}

vector<int> lps;

int f(int cnt) {
  if (cnt == k) return 1;

  int &ans = dp[cnt];
  if (ans != -1) return ans;

  ans = 0;
  for (int i = 0; i < n; i++) {
    if (cnt + i > k) continue;
    if (lps[i] == 0) {
      ans = (ans + f((i + 1) + cnt)) % mod;
    }
  }

  return ans;
}

void solve() {
  cin >> n >> k >> s;
  lps = build_lps(s);

  memset(dp, -1, sizeof dp);
  cout << f(0) << '\n';
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