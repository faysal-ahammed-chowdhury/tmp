#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[k + 1], b[n + 1];
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  vector<int> v;
  while (true) {
    int idx = -1;
    for (int i = 1; i <= n; i++) {
      if (b[i] == k + 1) continue;
      if (idx == -1) idx = i;
      else {
        if (b[i] > b[idx]) idx = i;
      }
    }

    if (idx == -1) break;

    int need = (k + 1) - b[idx];
    for (int i = 1; i <= need; i++) {
      v.push_back(idx);
      b[idx]++;
    }
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