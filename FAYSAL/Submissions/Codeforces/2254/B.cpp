#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  int ans = 0;
  char last = '.';
  int cnt = 0;
  vector<pair<char, int>> v;
  for (int i = 1; i <= n; i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    }
    else {
      ans++;
      if (last != '.') v.push_back({last, cnt});
      cnt = 1;
    }

    last = s[i];
  }

  v.push_back({last, cnt});

  bool kombe2 = false, kombe1 = false;
  for (int i = 1; i + 1 < v.size(); i++) {
    auto [c1, _] = v[i - 1];
    auto [c2, cnt] = v[i];
    auto [c3, __] = v[i + 1];

    if (cnt == 1) {
      kombe1 = true;
      if (c1 == c3) kombe2 = true;
    }
  }

  if (kombe2) ans -= 2;
  else if (kombe1) ans--;

  cout << ans << '\n';
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