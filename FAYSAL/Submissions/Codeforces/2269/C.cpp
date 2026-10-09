#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 1e5 +  9;
int n, k, a[N];
int pref[N];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  int katmu = n - (k - 1);

  int l = k, r = n - k + 1;
  if (l <= r) {
    if (r - l + 1 <= katmu) {
      int ans = 0;
      ans += pref[r] - pref[l - 1];
      katmu -= r - l + 1;

      int m = n - (r - l + 1);
      int lo = r + (k - l + 1);
      int hi = m - k + 1;
      // cout << hi << '\n';
      while (katmu > 0 and lo >= 1 and hi <= n) {
        ans += max(a[lo], a[hi]);
        lo++, hi--;
        katmu--;
      }

      cout << ans << '\n';
    }
    else {
      int ans = 0;
      for (int i = 1; i <= katmu; i++) {
        int lft = l + i - 1;
        int rem = katmu - i;
        int rght = r - rem + 1;
        int cur = pref[lft] - pref[l - 1];
        cur += pref[r] - pref[rght - 1];
        ans = max(ans, cur);
      }
      cout << ans << '\n';
    }
  }
  else {
    int ans = 0;
    while (katmu > 0 and l >= 1 and r <= n) {
      ans += max(a[l], a[r]);
      l++, r--;
      katmu--;
    }

    cout << ans << '\n';
  }
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