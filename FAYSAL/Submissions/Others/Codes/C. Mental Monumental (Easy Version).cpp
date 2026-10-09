#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];

bool ok(int mex) {
  set<int> missing_numbers;
  for (int i = 0; i <= n + 2; i++) {
    missing_numbers.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] < mex and missing_numbers.find(a[i]) != missing_numbers.end()) {
      missing_numbers.erase(a[i]);
      continue;
    }
    int mx = a[i] % ((a[i] / 2) + 1);
    if (*missing_numbers.begin() <= mx) {
      missing_numbers.erase(missing_numbers.begin());
    }
  }

  return *missing_numbers.begin() >= mex;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);

  int l = 0, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
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