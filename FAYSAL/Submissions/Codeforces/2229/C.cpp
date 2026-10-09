#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  vector<int> ans;
  for (int i = n; i >= 1; i--) {
    int x = a[i];
    if (cnt % 2 == 1) x = -x;

    if (x > 0) {
      ans.push_back(i);
      cnt++;
    }
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
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