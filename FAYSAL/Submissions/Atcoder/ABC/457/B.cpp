#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    int len; cin >> len;
    while (len--) {
      int x; cin >> x;
      a[i].push_back(x);
    }
  }

  int x, y; cin >> x >> y;
  cout << a[x][y - 1] << '\n';

  return 0;
}