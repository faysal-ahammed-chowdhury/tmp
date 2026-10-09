#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  bool ok = true;
  map<int, int> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    if (i <= n - k or i > k) {
      ok &= (a[i] == b[i]) or (b[i] == -1);
    }
    else {
      mp1[a[i]]++;
      mp2[b[i]]++;
    }
  }

  int cnt = mp2[-1];
  for (auto [x, _] : mp1) {
    if (mp2[x] == 0) {
      cnt--;
    }
  }

  if (cnt == 0 and ok) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
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