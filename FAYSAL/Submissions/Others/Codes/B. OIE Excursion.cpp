#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }


  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    }
    else {
      if (cnt >= m) {
        cout << "NO\n";
        return;
      }
      cnt = 1;
    }
  }

  if (cnt >= m) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
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