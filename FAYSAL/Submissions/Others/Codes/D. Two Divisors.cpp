#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e7 + 9;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n; cin >> n;
  int a[n + 1];
  vector<int> pf[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = spf[x], tot = 1;
      while (x % p == 0) {
        x /= p;
        tot *= p;
      }
      pf[i].push_back(tot);
    }
  }

  vector<int> ans1, ans2;

  for (int i = 1; i <= n; i++) {
    bool ok = false;
    int cur = 1;
    for (int j = 0; j < pf[i].size(); j++) {
      cur *= pf[i][j];
      int rem = a[i] / cur;
      if (min(rem, cur) == 1) continue;
      if (__gcd(cur + rem, a[i]) == 1) {
        ans1.push_back(cur);
        ans2.push_back(rem);
        ok = true;
        break;
      }
    }
    if (!ok) {
      ans1.push_back(-1);
      ans2.push_back(-1);
    }
  }

  for (auto x : ans1) {
    cout << x << ' ';
  }
  cout << '\n';
  for (auto x : ans2) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}