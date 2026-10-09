#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  int a[n + 1];
  vector<int> v1, v2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i]) v1.push_back(i);
    else v2.push_back(i);
  }

  string s; cin >> s;

  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) cnt++;
    else ans += cnt;
  }

  cout << ans << ' ';
  if (ans == 0) {
    for (int i = 1; i <= n; i++) {
      cout << ans << ' ';
    }
    cout << '\n';
    return;
  }

  int st = 0, en = v2.size() - 1;
  for (int i = 1; i <= n; i++) {
    if (ans == 0) {
      cout << ans << ' ';
      continue;
    }
    if (s[i - 1] == '1') {
      int l = 0, r = en, cur = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (v2[mid] > v1[st]) {
          cur = mid;
          r = mid - 1;
        }
        else l = mid + 1;
      }

      if (cur != -1) {
        int koyta = en - cur + 1;
        ans -= koyta;
      }

      cout << ans << ' ';

      st++;
      continue;
    }

    int l = st, r = v1.size() - 1, cur = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (v1[mid] < v2[en]) {
        cur = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }

    if (cur != -1) {
      int koyta = cur - st + 1;
      ans -= koyta;
    }

    cout << ans << ' ';
    en--;
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