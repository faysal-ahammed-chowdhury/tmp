#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt1 = 0, cnt2 = 0;
  for (auto c : s) {
    cnt1 += c == '(';
    cnt2 += c == ')';
  }

  if (cnt1 == cnt2) cout << "YES\n";
  else cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}