#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string a, b; cin >> a >> b;
  a = '.' + a;
  b = '.' + b;

  multiset<char> se1, se2, se3, se4;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      se1.insert(a[i]);
      se2.insert(b[i]);
    }
    else {
      se3.insert(a[i]);
      se4.insert(b[i]);
    }
  }

  if ((se1 == se2 and se3 == se4)) cout << "YES\n";
  else cout << "NO\n";
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