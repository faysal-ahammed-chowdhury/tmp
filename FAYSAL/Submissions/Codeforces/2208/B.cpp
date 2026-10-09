#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 5005;
int n, k, p, m;
int a[N];

void solve() {
  cin >> n >> k >> p >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (n == k) {
    cout << m / a[p] << '\n';
    return;
  }

  int cut = max(0ll, p - k);
  bool flag = false;
  while (cut > 0) {
    flag = true;
    int idx = 1;
    for (int i = 1; i <= k; i++) {
      if (a[i] < a[idx]) idx = i;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (idx == i) continue;
      v.push_back(a[i]);
    }
    v.push_back(a[idx]);

    m -= a[idx];

    for (int i = 1; i <= n; i++) {
      a[i] = v[i - 1];
    }
    cut--;
  }

  if (m < 0) {
    cout << 0 << '\n';
    return;
  }

  if (flag) p = k;

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (p == i) continue;
    v.push_back(a[i]);
  }
  v.push_back(a[p]);

  m -= a[p];

  for (int i = 1; i <= n; i++) {
    a[i] = v[i - 1];
  }

  if (m < 0) {
    cout << 0 << '\n';
    return;
  }

  int ans = 1;
  p = n;

  int cost = a[p];
  cut = max(0ll, p - k);
  while (cut > 0) {
    int idx = 1;
    for (int i = 1; i <= k; i++) {
      if (a[i] < a[idx]) idx = i;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (idx == i) continue;
      v.push_back(a[i]);
    }
    v.push_back(a[idx]);

    cost += a[idx];

    for (int i = 1; i <= n; i++) {
      a[i] = v[i - 1];
    }
    cut--;
  }


  ans += m / cost;

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