#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  vector<int> v;
  v.push_back(1e9);
  for (auto [x, cnt] : mp) {
    v.push_back(cnt);
  } 

  int sz = v.size() - 1;
  sort(v.rbegin(), v.rend());

  int sum = 0;
  int ans = 0;
  for (int i = 1; i <= sz; i++) {
    sum += v[i];

    if (i + 1 <= sz and v[i] == v[i + 1]) continue;

    int cur = sum - (i * (v[i] - 1));
    int need = k - cur;
    if (need >= 0 and (need % i) == 0) ans++;
  }

  cout << ans << '\n';
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