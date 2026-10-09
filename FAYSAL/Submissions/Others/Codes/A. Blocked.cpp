#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    v.push_back(x);
    mp[x]++;
  }

  for (auto [x, cnt] : mp) {
    if (cnt > 1) {
      cout << -1 << '\n';
      return;
    }
  }

  sort(v.rbegin(), v.rend());

  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';
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