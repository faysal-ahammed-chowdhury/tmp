#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
vector<int> divs[N];
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
      if (is_prime[i] and j > i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<int> v = divs[n];
  int sz = v.size();
  vector<int> start(sz, false);

  for (int i = 0; i < sz; i++) {
    int x = v[i];
    // cout << x << ' ';
    if (is_prime[x]) start[i] = true;
  }
  // cout << '\n';

  vector<int> nxt(sz, -1);
  int last = -1;
  for (int i = sz - 1; i >= 0; i--) {
    if (start[i]) last = i;
    nxt[i] = last;
  }

  int idx = -1;
  for (int i = 0; i < sz; i++) {
    if (start[i]) {
      continue;
    }
    if (idx == -1) {
      idx = i;
      // cout << v[idx] << '\n';
      start[i] = true;
      continue;
    }
    if (v[i] % v[idx] == 0) {
      idx = i;
      // cout << v[idx] << '\n';
      start[i] = true;
      continue;
    }
  }

  int ans = 0;
  for (auto x : start) {
    ans += x;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}