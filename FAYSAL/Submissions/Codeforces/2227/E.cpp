#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, K = 20;
int a[N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); 
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]);
}

bool ok(int l, int r, int x) {
  return query(l, r) >= x;
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(n);

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    int mn = query(i + 1, n);

    ans += max(0ll, a[i] - mn);
  }

  ll tmp = ans;
  for (int i = 1; i <= n; i++) {
    ll cur = tmp;
    if (i + 1 <= n) {
      int mn = query(i + 1, n);
      if (mn < a[i]) cur--;
    }

    int l = 1, r = i, idx = i;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, i, a[i])) {
        idx = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }

    ans = max(ans, cur + i - idx);
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