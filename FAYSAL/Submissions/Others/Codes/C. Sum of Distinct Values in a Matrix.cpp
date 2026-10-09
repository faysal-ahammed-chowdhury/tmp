#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5 + 9;
int x, y;
int a[N], b[N];

int f(int n, int m) {
  set<int, greater<>> se1, se2, common;
  for (int i = 1; i <= x; i++) {
    se1.insert(a[i]);
  }
  for (int i = 1; i <= y; i++) {
    if (se1.find(b[i]) != se1.end()) {
      se1.erase(b[i]);
      common.insert(b[i]);
    }
    else se2.insert(b[i]);
  }

  int ans = 0;

  int tot = n + m - 1;
  set<int> taken;
  while (se1.size() > 0 and n) {
    taken.insert(*se1.begin());
    ans += *se1.begin();
    se1.erase(se1.begin());
    n--;
  }

  while (se2.size() > 0 and m) {
    taken.insert(*se2.begin());
    ans += *se2.begin();
    se2.erase(se2.begin());
    m--;
  }

  while (taken.size() < tot and common.size() > 0) {
    ans += *common.begin();
    taken.insert(*common.begin());
    common.erase(common.begin());
  }

  while (common.size() > 0) {
    int mn = taken.size() ? *taken.begin() : 0;
    int mx = *common.begin();
    if (mx <= mn) break;

    taken.erase(mn);
    common.erase(common.begin());
    taken.insert(mx);

    ans -= mn;
    ans += mx;
  }

  if (taken.size() > tot) {
    ans -= *taken.begin();
  }

  return ans;
}

void solve() {
  int n, m; cin >> n >> m >> x >> y;
  for (int i = 1; i <= x; i++) cin >> a[i];
  for (int i = 1; i <= y; i++) cin >> b[i];

  int ans = f(n, m);
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