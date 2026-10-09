#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  vector<int> six, three, two, other;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 6 == 0) six.push_back(a[i]);
    else if (a[i] % 3 == 0) three.push_back(a[i]);
    else if (a[i] % 2 == 0) two.push_back(a[i]);
    else other.push_back(a[i]);
  }

  for (auto x : six) {
    cout << x << ' ';
  }
  for (auto x : three) {
    cout << x << ' ';
  }
  for (auto x : other) {
    cout << x << ' ';
  }
  for (auto x : two) {
    cout << x << ' ';
  }
  cout << '\n';
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