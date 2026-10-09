#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    int len; cin >> len;
    while (len--) {
      int x; cin >> x;
      a[i].push_back(x);
    }
  }

  int c[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= n; i++) {
    int len = a[i].size();
    int cnt = len * c[i];
    if (k <= cnt) {
      cout << a[i][(k - 1) % len] << '\n';
      return 0;
    }
    else {
      k -= cnt;
    }
  }

  return 0;
}