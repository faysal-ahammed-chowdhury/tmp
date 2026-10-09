#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 3e5 + 9;
int spf[N];

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void solve() {
  int n, x; cin >> n >> x;
  vector<int> pf;
  while (x > 1) {
    int p = spf[x];
    pf.push_back(p);
    while (x % p == 0) {
      x /= p;
    }
  }

  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int org = x;
    while (x > 1) {
      int p = spf[x];
      for (auto y : pf) {
        if (p == y) {
          mp[p] += org;
          break;
        }
      }
      while (x % p == 0) {
        x /= p;
      }
    }
  }

  int ans = 0;
  for (auto [_, x] : mp) {
    ans = max(ans, x);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}