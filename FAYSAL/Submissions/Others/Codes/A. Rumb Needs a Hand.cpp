#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  for (int i = 1;  i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);

  set<int> se;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      se.insert(i);
      v.push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (se.find(i) != se.end()) {
      c[i] = a[v.back()];
      v.pop_back();
    }
    else c[i] = a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (c[i] != b[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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