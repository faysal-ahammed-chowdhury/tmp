#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n;
  if (n % 12 != 10) {
    cout << (n % 12) << ' ' << (n - (n % 12)) << '\n';
    return;
  }

  for (int i = 1; i <= 1000; i++) {
    string s = to_string(i);
    string t = s;
    reverse(t.begin(), t.end());

    string a = s + t;
    ll x = stol(a);

    if ((n - x) % 12 == 0 and (n - x) >= 0) {
      cout << x << ' ' << n - x << '\n';
      return;
    }

    if (i >= 10) {
      string b = s + t.substr(1);
      ll x = stol(b);
      if ((n - x) % 12 == 0 and (n - x) >= 0) {
        cout << x << ' ' << n - x << '\n';
        return;
      }
    }
  }

  cout << -1 << '\n';
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