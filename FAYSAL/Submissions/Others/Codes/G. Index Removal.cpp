#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e5 + 9;
int n, k, a[N];
ll pref[N];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  cout << "0 ";
  for (int i = 2; i < n; i++) {
    int prv = a[i - 1];
    int l = i + 1, r = n, idx = n + 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int el = mid - (i + 1) + 2;
      int ex = prv + ((el - 1) * k);
      if (a[mid] <= ex) {
        idx = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }

    int el = (idx - 1) - (i - 1);
    int last = (prv + (el - 1) * k);
    int ex_sum = (el * (prv + last)) / 2;
    int ac_sum = pref[idx - 1] - pref[i - 2] - a[i];
    // cout << ac_sum << '\n';

    cout << ac_sum - ex_sum << ' ';
  }
  cout << "0\n";
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