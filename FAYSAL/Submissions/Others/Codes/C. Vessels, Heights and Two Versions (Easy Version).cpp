#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    vector<int> v;
    v.push_back(0);
    for (int j = i; j <= n; j++) {
      v.push_back(a[j]);
    }
    for (int j = 1; j < i; j++) {
      v.push_back(a[j]);
    }

    int mx = 0;
    int w[n + 1];
    w[1] = 0;
    for (int j = n; j >= 2; j--) {
      mx = max(mx, v[j]);
      w[j] = mx;
    }

    ll ans = 0;
    for (int j = 2; j <= n; j++) {
      int here = max(w[j - 1], w[j]);
      if (here > v[j - 1]) {
        if (w[j - 1] > v[j - 1]) {
          w[j] = w[j - 1];
        }
        else {
          w[j] = v[j - 1];
        }

        // cout << j - 1 << ' ' << v[j - 1] << ' ' << w[j - 1] << ' ' << w[j] << '\n';
      }
      else break;

      // cout << w[j] << ' ';
    }
    // cout << '\n';

    for (int j = 1; j <= n; j++) {
      ans += w[j];
    }

    cout << ans << ' ';
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