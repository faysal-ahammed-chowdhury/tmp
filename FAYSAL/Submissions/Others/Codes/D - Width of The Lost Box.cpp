#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int L, H, K;

bool ok(int d) {
  int a = L / d;
  int b = H / d;
  return a * b >= K;
}

int cs;
void solve() {
  cin >> L >> H >> K;

  int l = 1, r = 2e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }

  cout << "Case " << ++cs << ": ";
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