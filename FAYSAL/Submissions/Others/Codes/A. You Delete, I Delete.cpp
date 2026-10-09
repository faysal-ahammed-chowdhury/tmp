#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;

  int idxo = -1, idxz = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0' and idxz == -1) {
      idxz = i;
    }
    if (s[i] == '1' and idxo == -1) {
      idxo = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i == idxo or i == idxz) continue;
    cout << s[i];
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