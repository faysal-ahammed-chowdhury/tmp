#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5 + 9;
int a[N];
bool cur[N];
int n, q; 
// vector<int> vec;
// bool ok[N];

// void prec() {
//   vector<int> v = {3, 6, 9, 12, 15};
//   for (int mask = 0; mask < 32; mask++) {
//     int xr = 0;
//     for (int i = 0; i < 5; i++) {
//       if (mask & (1ll << i)) xr ^= v[i];
//     }
//     vec.push_back(xr);
//     // cout << xr << '\n';
//   }
//   sort(vec.begin(), vec.end());
//   vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
// }

bool calc(int i) {
  if (a[i] % 3 == 0) return true;
  if (a[i] == 5 or a[i] == 10) return true;
  return false;
}

void solve() {
  cin >> n >> q;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    bool res = calc(i);
    ans += res;
    cur[i] = res;
  }
  cout << ans << ' ';

  while (q--) {
    int i, x; cin >> i >> x;
    a[i] = x;
    ans -= cur[i];
    bool res = calc(i);
    cur[i] = res;
    ans += res;

    cout << ans << ' ';
  }
  cout << '\n';
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