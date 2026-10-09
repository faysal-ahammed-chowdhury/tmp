#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  string a, b; cin >> a >> b;
  a = '.' + a;
  b = '.' + b;

  multiset<char> se1, se2, se3, se4;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      se1.insert(a[i]);
      se2.insert(b[i]);
    }
    else {
      se3.insert(a[i]);
      se4.insert(b[i]);
    }
  }

  if (!(se1 == se2 and se3 == se4)) {
    cout << "-1\n";
    return;
  }

  vector<int> one_odd_a, one_odd_b;
  vector<int> one_even_a, one_even_b;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      if (a[i] == '1') one_odd_a.push_back(i);
      if (b[i] == '1') one_odd_b.push_back(i);
    }
    else {
      if (a[i] == '1') one_even_a.push_back(i);
      if (b[i] == '1') one_even_b.push_back(i);
    }
  }

  int ans = 0;
  for (int i = 0; i < one_odd_a.size(); i++) {
    ans += abs(one_odd_a[i] - one_odd_b[i]);
  }
  for (int i = 0; i < one_even_a.size(); i++) {
    ans += abs(one_even_a[i] - one_even_b[i]);
  }

  cout << ans / 2 << '\n';
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