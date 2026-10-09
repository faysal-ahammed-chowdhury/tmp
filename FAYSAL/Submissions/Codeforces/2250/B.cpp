#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int p = n - 2;
  if (k > p) {
    cout << -1 << '\n';
    return;
  }

  int one = (n + 1) / 2;
  int zero = n / 2;

  int a = (k + 1) / 2;
  int b = k / 2;

  string ans = "";
  for (int i = 1; i <= a + 1; i++) {
    one--;
    ans += '1';
  }
  for (int i = 1; i <= b + 1; i++) {
    zero--;
    ans += '0';
  }

  if (one < zero) {
    zero--;
    ans = "0" + ans;
  } 

  for (int i = 1; i <= one + zero; i++) {
    if (i & 1) ans += '1';
    else ans += '0';
  }

  assert(ans.size() == n);

  int cnt = 0;
  for (int i = 1; i < n; i++) {
    cnt += ans[i] == ans[i - 1];
  }

  assert(cnt == k);
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