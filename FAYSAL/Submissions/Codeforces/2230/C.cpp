#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int one = 0;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    one += a[i] == 1;
  }
  sort(a + 1, a + n + 1);

  int ans = 0;
  int cnt = 0;
  for (int i =1; i <= n; i++) {
    if (a[i] == 1) continue;
    cnt++;

    int possible = (a[i] / 2) - 1;
    int x = min(possible, one);

    ans += a[i];
    ans += x;
    one -= x;
  }

  if (cnt == 1 and one) ans++;
  if (ans < 3) ans = 0;

  cout << ans << '\n';
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