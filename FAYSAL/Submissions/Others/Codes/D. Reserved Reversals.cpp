#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;

void solve() {
  int n; cin >> n;
  vector<int> odd, even;
  int odd_mn = inf, odd_mx = -1;
  int even_mn = inf, even_mx = -1;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) {
      odd.push_back(x);
      odd_mn = min(odd_mn, x);
      odd_mx = max(odd_mx, x);
    }
    else {
      even.push_back(x);
      even_mn = min(even_mn, x);
      even_mx = max(even_mx, x);
    }
  }

  for (int i = 1; i < even.size(); i++) {
    if (even[i - 1] <= even[i]) continue;
    if (odd_mn <= even[i] or odd_mx >= even[i - 1]) {
      swap(even[i - 1], even[i]);
    }
    else {
      cout << "NO\n";
      return;
    }
  }

  for (int i = 1; i < odd.size(); i++) {
    if (odd[i - 1] <= odd[i]) continue;
    if (even_mn <= odd[i] or even_mx >= odd[i - 1]) {
      swap(odd[i - 1], odd[i]);
    }
    else {
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