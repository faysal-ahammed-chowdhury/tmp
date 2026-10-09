#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, a[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans[n + 1];
  ans[1] = a[1];
  int extra = 0;
  int mn = a[1];
  cout << ans[1] << ' ';
  int sum = a[1];
  for (int i = 2; i <= n; i++) {
    sum += a[i];
    int x = (ans[i - 1] * (i - 1)) + a[i] + extra;
    // cout << extra << '\n';
    int avg = (x / i);
    avg = min(avg, mn);

    ans[i] = avg;
    mn = min(mn, ans[i]);
    extra = sum - (i * ans[i]);

    cout << ans[i] << ' ';
  }
  cout << '\n';

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