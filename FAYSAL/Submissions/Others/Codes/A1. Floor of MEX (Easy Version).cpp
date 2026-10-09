#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int forbidden[n + 1];
  memset(forbidden, 0, sizeof forbidden);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int l = x * i, r = l + i - 1;
    if (l <= n) forbidden[l]++;
    if (r + 1 <= n) forbidden[r + 1]--;
  }

  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (i > 0) forbidden[i] += forbidden[i - 1];
    if (forbidden[i] == false) v.push_back(i);
  }

  cout << v.size() << '\n';
  for (auto x : v) {
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