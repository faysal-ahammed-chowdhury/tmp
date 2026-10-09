#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<pair<int, int>> v;
  int tot = 0;
  for (int i = 0; i < s.size(); i++) {
    v.push_back({s[i] - '0', i + 1});
    tot += s[i] - '0';
  }
  sort(v.rbegin(), v.rend());

  int val = -1;
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    auto [x, idx] = v[i];
    if (idx == 1) {
      val = x - 1;
      continue;
    }
    if (tot >= 10) {
      if (val != -1 and val >= x) {
        tot -= val;
        ans++;
        val = -1;
      }

      if (tot >= 10) {
        tot -= x;
        ans++;
      }
    }
  }

  if (val != -1 and tot >= 10) {
    tot -= val;
    ans++;
  }

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