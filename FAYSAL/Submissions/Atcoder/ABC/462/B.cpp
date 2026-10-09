#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v[n + 1];
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    for (int j = 1; j <= k; j++) {
      int x; cin >> x;
      v[x].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << v[i].size() << ' ';
    sort(v[i].begin(), v[i].end());
    for (auto x : v[i]) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}