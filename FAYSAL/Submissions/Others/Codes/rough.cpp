#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9, inf = 1e9;
int n, last[N], a[N], b[N];
array<int, 3> Q[N];

void solve() {
  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= q; i++) {
    cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
  }

  set<int> se;
  map<int, int> mp;
  for (int i = q; i >= 1; i--) {
    int x = Q[i][0], y = Q[i][1], z = Q[i][2];
    if (se.find(z) == se.end()) {
      se.insert(z);
      mp.erase(z);
      mp[x] = max(mp[x], b[z]);
      mp[y] = max(mp[y], b[z]);
      continue;
    }
    if (mp.find(z) == mp.end()) continue;
    int val = mp[z];
    mp.erase(z);
    mp[x] = max(mp[x], val);
    mp[y] = max(mp[y], val);
  }

  for (int i = 1; i <= n; i++) {
    if (se.find(i) == se.end()) a[i] = b[i];
    else if (mp.find(i) != mp.end()) a[i] = mp[i];
    else a[i] = 0;
    last[i] = a[i];
    // cout << last[i] << ' ';
  }
  // cout << '\n';

  for (int i = 1; i <= q; i++) {
    int x = Q[i][0], y = Q[i][1], z = Q[i][2];
    last[z] = min(last[x], last[y]);
  }

  for (int i = 1; i <= n; i++) {
    if (last[i] != b[i]) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
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