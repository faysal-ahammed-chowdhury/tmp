#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int freq[N];
ll dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  for (int i = 1; i <= 100000; i++) {
    dp[i] = dp[i - 1];
    ll x = 1ll * freq[i] * i; 
    dp[i] = max(dp[i], x + (i - 2 >= 0 ? dp[i - 2] : 0));
  }

  ll ans = max(dp[100000], dp[100000 - 1]);
  cout << ans << '\n';

  return 0;
}