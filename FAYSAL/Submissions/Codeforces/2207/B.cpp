#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, m, l;
int a[N];

void solve() {
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  m = min(m, n + 1);

  if (m == 1) {
    cout << l - a[n] << '\n';
    return;
  }

  multiset<int> ms;
  for (int i = 1; i <= m; i++) {
    ms.insert(0);
  }

  int j = 1;
  for (int time = 1; time <= a[n]; time++) {
    int x = *ms.begin();
    x++;
    ms.erase(ms.begin());
    ms.insert(x);
    if (j <= n and a[j] == time) {
      auto it = ms.end();
      --it;
      ms.erase(it);
      int rem = n - j;
      if (rem >= ms.size()) ms.insert(0);
      j++;
    }
  }

  auto it = ms.end();
  --it;
  cout << (*it) + l - a[n] << '\n';
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