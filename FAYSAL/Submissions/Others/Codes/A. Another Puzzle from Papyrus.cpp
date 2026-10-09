#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n, c; cin >> n >> c;
  int a[n + 1], b[n + 1];
  int arr[n + 1];
  int arr2[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    arr[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    arr2[i] = b[i];
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  bool ok = true;
  int ans1 = c, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= b[i]) ans1 += a[i] - b[i];
    else {
      cout << -1 << '\n';
      return;
    }

    if (arr[i] >= arr2[i]) ans2 += arr[i] - arr2[i];
    else ok = false;
  }

  if (ok) ans1 = min(ans1, ans2);

  cout << ans1 << '\n';
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