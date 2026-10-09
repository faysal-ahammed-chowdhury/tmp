#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> v;
for (auto c : s) {
    if (v.empty()) v.push_back(c);
    else if (v.back() != c) v.push_back(c);
  }

  if (v.size() == 2) cout << 2 << '\n';
  else cout << 1 << '\n';
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