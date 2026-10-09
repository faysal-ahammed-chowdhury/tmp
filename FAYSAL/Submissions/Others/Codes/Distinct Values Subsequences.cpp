#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 1e9 + 7;
int n;
map<int, int> mp;
vector<int> v;

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  for (auto [x, cnt] : mp) {
    v.push_back(cnt);
  }

  sort(v.rbegin(), v.rend());

  int sz = v.size();
  vector<int> suff(sz + 1);
  suff[sz] = 1;
  for (int i = sz - 1; i >= 0; i--) {
    suff[i] = 1ll * suff[i + 1] * (v[i] + 1) % mod;
  }

  int cnt = 0, ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    if (x == 1) break;
    int here = power(2, x, mod) - x - 1;
    // cout << i << ' ' << suff[i + 1] << '\n';
    ans += (1ll * here * power(2, cnt, mod) % mod) * suff[i + 1] % mod;
    ans %= mod;
    cnt += x;
  }

  ans = power(2, n, mod) - ans;
  if (ans < 0) ans += mod;
  ans--;
  if (ans < 0) ans += mod;
  cout << ans << '\n';

  return 0;
}