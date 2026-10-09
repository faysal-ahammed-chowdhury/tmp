#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 2]; a[0] = 0; a[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) ans++;
  }

  int add = 0;
  for (int i = 1; i <= n; i++) {
    if (i + 3 <= n and a[i] == a[i + 1] and a[i + 2] == a[i + 3] and a[i + 1] != a[i + 2]) {
      add = 2;
    }
    else if (a[i - 1] != a[i + 1] and i + 2 <= n and a[i + 1] == a[i + 2] and a[i] != a[i + 1]) {
      add = max(add, 1);
    }
    else if (i + 3 <= n + 1 and a[i] == a[i + 1] and a[i + 1] != a[i + 2] and a[i + 1] != a[i + 3]) {
      add = max(add, 1);
    }
  }

  ans += add;

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