#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  set<int> even, odd;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    if (i & 1) odd.insert(a[i]);
    else even.insert(a[i]);
  }


  bool rev = false;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    // cout << last << '\n';
    if (last == mx) rev |= true;
    if (i & 1) {
      if (!rev) {
        auto it = odd.upper_bound(last);
        if (it == odd.end()) {
          cout << "NO\n";
          return;
        }
        int mn = *it;
        last = mn;
        odd.erase(it);
      }
      else {
        auto it = odd.end();
        --it;
        if (last < *it) {
          cout << "NO\n";
          return;
        }
        last = *it;
        odd.erase(it);
      }
    }
    else {
      if (!rev) {
        auto it = even.upper_bound(last);
        if (it == even.end()) {
          cout << "NO\n";
          return;
        }
        int mn = *it;
        last = mn;
        even.erase(it);
      }
      else {
        auto it = even.end();
        --it;
        if (last < *it) {
          cout << "NO\n";
          return;
        }
        last = *it;
        even.erase(it);
      }
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