#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  multiset<int, greater<>> ms;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ms.insert(x);
    mp[x]++;
  }

  int ans = 0;
  while (true) {
    int x = *ms.begin();
    int y = *ms.rbegin();

    if (mp.size() == 1) break;
    if (mp.size() == 2 and (x % 2 == 0) and (y == x - 1)) {
      if (x / 2 == y) {
        ans += min(mp[x], mp[y]);
      }
      else ans += mp[y];
      break;
    }

    int nwx = x;
    if (nwx & 1) nwx++;
    else nwx /= 2;

    mp[x]--;
    if (mp[x] == 0) mp.erase(x);
    mp[nwx]++;

    ms.erase(ms.begin());
    ms.insert(nwx);
    ans++;
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