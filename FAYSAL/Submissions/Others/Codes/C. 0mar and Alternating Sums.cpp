#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 1e9 + 7;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  vector<pair<int, int>> v;
  v.push_back({ -100, 100});
  int ans = 1;
  for (auto [x, cnt] : mp) {
    v.push_back({x, cnt});
    ans = 1ll * ans * power(2, cnt - 1, mod) % mod;
  }


  int cnt = 0;
  if (v[1].first == -1) {
    int sz = v.size() - 1;
    for (int i = 2; i <= sz; i++) {
      if (!(i + 1 <= sz and v[i].first == v[i + 1].first - 1)) continue;
      cnt++;
    }
  }

  ans = (ans + (1ll * ans * cnt % mod)) % mod;

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