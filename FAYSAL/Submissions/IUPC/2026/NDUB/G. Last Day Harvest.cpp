#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int x, y; cin >> x >> y;

  vector<int> divs1, divs2, divs;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      divs1.push_back(i);
      if (i != (x / i)) divs1.push_back(x / i);
    }
  }
  for (int i = 1; i * i <= y; i++) {
    if (y % i == 0) {
      divs2.push_back(i);
      if (i != (y / i)) divs2.push_back(y / i);
    }
  }

  for (auto d1 : divs1) {
    for (auto d2 : divs2) {
      divs.push_back(d1 * d2);
    }
  }

  sort(divs.begin(), divs.end());
  divs.resize(unique(divs.begin(), divs.end()) - divs.begin());

  vector<pair<int, int>> ans;
  for (auto d : divs) {
    int a = (x * y) / d, b = d;
    int p = x + a;
    int q = y + b;
    ans.push_back({p, q});
  }

  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

  cout << ans.size() << '\n';
  for (auto [p, q] : ans) {
    cout << p << ' ' << q << '\n';
  }
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