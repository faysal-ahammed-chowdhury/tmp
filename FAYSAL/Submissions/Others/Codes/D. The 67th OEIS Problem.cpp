#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

void solve() {
  int n; cin >> n;
  int org_n = n;

  int bit = __lg(n);
  if (__builtin_popcount(n) > 1) bit++;

  n = bit + 1;

  int a[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  // int x = 1;
  // for (int i = 0; i < 14; i++) {
  //   x *= a[i];
  // }
  // cout << (x <= 1e18) << '\n';

  vector<int> v;
  for (int mask = 0; mask < (1 << n); mask++) {
    int x = 1;
    for (int i = 0; i < n; i++) {
      if (CHECK(mask, i)) x *= a[i];
    }
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  set<int> se;
  int cnt = 1;
  int last = v.back();
  cout << v.back() << ' ';
  for (int i = v.size() - 1; i >= 0; i--) {
    int x = __gcd(v.back(), last);
    if (cnt >= org_n) continue;
    if (se.find(x) == se.end() and x > 1) {
      last = v.back();
      cout << last << ' ';
      se.insert(x);
      cnt++;
    }
    if (cnt >= org_n) continue;
    if (se.find(__gcd(last, v[i])) == se.end() and __gcd(last, v[i]) > 1)  {
      cout << v[i] << ' ';
      se.insert(__gcd(last, v[i]));
      last = v[i];
      cnt++;
    }
  }
  if (cnt < org_n) {
    cnt++;
    se.insert(1);
  }

  assert(cnt == org_n);
  assert(se.size() == org_n - 1);

  if (cnt < org_n) cout << 1 << '\n';
  else cout << '\n';

  // cout << org_n << '\n';
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