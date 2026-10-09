#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, mx_c, r;
int a[N], b[N];

void solve() {
  cin >> n >> mx_c >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int cur = mx_c - a[1];
  if (a[1] > mx_c) {
    cout << "Impossible\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    b[i] = cur;
    if (i < n) {
      cur += r;
      cur = min(cur, mx_c);
      cur -= a[i + 1];

      if (cur < 0) {
        cout << "Impossible\n";
        return;
      }
    }
  }

  string ans = "";
  for (int i = 0; i <= n; i++) {
    ans += '1';
  }
  ans[n] = '0';

  int koto = a[n];
  for (int i = n - 1; i >= 1; i--) {
    if (b[i] >= koto) {
      ans[i] = '0';
      koto += a[i];
    }
    else {
      koto -= r;
      koto = max(0ll, koto);
      koto += a[i];
    }
  }

  cout << ans.substr(1) << '\n';
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