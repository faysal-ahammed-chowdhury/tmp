#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 5e5 + 9;
int n, a[N], b[N];

void solve() {
  cin >> n;
  map<int, vector<int>> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp1[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    mp2[b[i]].push_back(i);
  }

  int end[n + 5], normal_end[n + 5];
  int ans = 0;
  memset(end, 0, sizeof end);
  memset(normal_end, 0, sizeof normal_end);

  for (int i = n; i >= 1; i--) {
    if (a[i] != b[i]) {
      // normal_end[i] = n;
      continue;
    }
    auto it1 = upper_bound(mp1[a[i] + 1].begin(), mp1[a[i] + 1].end(), i);
    auto it2 = upper_bound(mp2[b[i] + 1].begin(), mp2[b[i] + 1].end(), i);

    if (it1 == mp1[a[i] + 1].end() and it2 == mp2[b[i] + 1].end()) {
      normal_end[i] = n;
      continue;
    }

    int mn = n;
    if (it1 != mp1[a[i] + 1].end()) {
      int idx = *it1;
      mn = min(mn, idx);
    }
    if (it2 != mp2[b[i] + 1].end()) {
      int idx = *it2;
      mn = min(mn, idx);
    }

    if (a[mn] == b[mn]) {
      normal_end[i] = normal_end[mn]; 
    }
    else {
      normal_end[i] = max(mn - 1, i);
    }

    // cout << i << ' ' << normal_end[i] << '\n';
  }

  for (int i = n; i >= 1; i--) {
    if (a[i] == 1 and b[i] == 1) {
      end[i] = normal_end[i];

      // cout << i << ' ' << end[i] << '\n';
      ans += max(0ll, end[i] - i + 1);
    }
    else if (a[i] != 1 and b[i] != 1) {
      auto it1 = upper_bound(mp1[1].begin(), mp1[1].end(), i);
      auto it2 = upper_bound(mp2[1].begin(), mp2[1].end(), i);

      if (it1 == mp1[1].end() and it2 == mp2[1].end()) {
        end[i] = n;
      }
      else {
        int mn = n;
        if (it1 != mp1[1].end()) {
          int idx = *it1;
          mn = min(mn, idx);
        }
        if (it2 != mp2[1].end()) {
          int idx = *it2;
          mn = min(mn, idx);
        }

        // cout << mn << '\n';

        if (a[mn] == b[mn]) {
          end[i] = normal_end[mn]; 
        }
        else {
          end[i] = max(mn - 1, i);
        }
      }

      // cout << i << ' ' << end[i] << '\n';
      ans += max(0ll, end[i] - i + 1);
    }
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