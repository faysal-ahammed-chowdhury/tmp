#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char get(char a, char b) {
  if (a != b) return '1';
  return '0';
}

void solve() {
  int n, k; cin >> n >> k;
  string a, b; cin >> a >> b;
  string c = "";

  int first_on = 0, last_on = 0, mid_on = 0;
  int first_off = 0, last_off = 0, mid_off = 0;
  for (int i = 0; i < n; i++) {
    c += get(a[i], b[i]);
    if (a[i] == '1') first_on++;
    else first_off++;

    if (b[i] == '1') last_on++;
    else last_off++;

    if (c[i] == '1') mid_on++;
    else mid_off++;
  }

  long long ans = (1ll * first_on * first_off) * (k > 1 ? 2ll : 1ll) + (1ll * last_on * last_off) * (k > 1 ? 2ll : 1ll) + (1ll * mid_on * mid_off);

  int cnt1 = 1, cnt2 = 2;
  bool kom = true;

  for (int i = 3; i <= k; i++) {
    ans += 1ll * cnt1 * (first_on * first_off);
    ans += 1ll * cnt1 * (last_on * last_off);
    ans += 1ll * cnt2 * (mid_on * mid_off);

    if (kom) {
      cnt2 *= 2;
      cnt2 -= 2;
      cnt1 = cnt2 + 1;
    }
    else {
      cnt2 *= 2;
      cnt2 += 2;
      cnt1 = cnt2 - 1;
    }

    kom ^= 1;
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