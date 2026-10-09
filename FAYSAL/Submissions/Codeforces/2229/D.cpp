#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int n, a[N], b[N];

bool ok(int mid) {
  int zero = 0, two = 0;
  int last = -1;
  for (int i = 1; i <= n; i++) {
    int x = (a[i] >= mid) + (b[i] >= mid);
    if (x == 2) {
      two++;
      last = 2;
    }
    else if (x == 0) {
      if (last != 0) zero++;
      last = 0;
    }
  }

  return two > zero;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int l = 1, r = 2 * n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

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