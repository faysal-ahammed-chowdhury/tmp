#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int p; cin >> p;

  int en = n;
  for (int i = n; i >= 1; i--) {
    if (a[i] == a[p]) en--;
    else break;
  }

  int last = -1;
  int right = 0;
  for (int i = p; i <= en; i++) {
    if (a[i] == last) continue;
    last = a[i];
    right++;
  }

  int st = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[p]) st++;
    else break;
  }

  last = -1;
  int left = 0;
  for (int i = st; i <= p; i++) {
    if (a[i] == last) continue;
    last = a[i];
    left++;
  }

  cout << max(left, right) << '\n';
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