#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 3e5 + 9;
int n, q;
string s;
int pref11[N], pref00[N], pref01[N];

bool ok(int cnt11, int cnt00, int cnt01, int T) {
  if (cnt11 > T) {
    cnt01 += cnt11 - T;
  }
  if (cnt00 > T) {
    cnt01 += cnt00 - T;
  }

  return cnt01 <= T;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q >> s;
  s = '.' + s;

  for (int i = 1; i <= n; i++) {
    pref00[i] = pref00[i - 1];
    pref11[i] = pref11[i - 1];
    pref01[i] = pref01[i - 1];

    if (s[i] == '1') {
      if (s[i - 1] == '0') pref01[i]++;
      else pref11[i]++;
    }
    else if (s[i - 1] == '0') {
      pref00[i]++;
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    if (l == r) {
      cout << 3 << '\n';
      continue;
    }

    int cnt00 = pref00[r] - pref00[l];
    int cnt11 = pref11[r] - pref11[l];
    int cnt01 = pref01[r] - pref01[l];

    if (s[l] == '0' and s[r] == '0') cnt00++;
    if (s[l] == '1' and s[r] == '1') cnt11++;
    if (s[l] == '1' and s[r] == '0') cnt01++;

    int lo = 1, hi = 4 * max({cnt11, cnt00, cnt01}), T = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (ok(cnt11, cnt00, cnt01, mid)) {
        T = mid;
        hi = mid - 1;
      }
      else {
        lo = mid + 1;
      }
    }

    int ans = (4 * T) - (r - l + 1);
    cout << ans << '\n';
  }

  return 0;
}