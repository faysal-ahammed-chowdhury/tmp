#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N];
ll b[N], pq[N], qp[N];

void solve() {
  int n, k, p, q; cin >> n >> k >> p >> q;
  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
    b[i] = min((a[i] % p) % q, (a[i] % q) % p);
    b[i] += b[i - 1];
    pq[i] = (a[i] % p) % q;
    pq[i] += pq[i - 1];
    qp[i] = (a[i] % q) % p;
    qp[i] += qp[i - 1];
  }

  ll ans = tot;
  for (int r = k; r <= n; r++) {
    int l = r - k + 1;
    ll cur = min(pq[r] - pq[l - 1], qp[r] - qp[l - 1]);
    cur += b[l - 1];
    cur += b[n] - b[r];
    ans = min(ans, cur);
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