#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int cnt = 0;
  int two = 0, three = 0, more = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    }
    else {
      if (cnt == 2) two++;
      else if (cnt == 3) three++;
      else if (cnt >= 4) more++;
      cnt = 1;
    }
  }

  if (cnt == 2) two++;
  else if (cnt == 3) three++;
  else if (cnt >= 4) more++;

  if (more >= 1 or three > 1) {
    cout << "NO\n";
    return;
  }

  if ((three and two) or two > 2) {
    cout << "NO\n";
    return;
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