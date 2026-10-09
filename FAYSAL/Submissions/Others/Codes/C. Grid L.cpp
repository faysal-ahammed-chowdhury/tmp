#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, m;
int nn;

bool ok(int col, int row) {
  int lagbe = col - row;
  int rem = (m - ((col + 1) * row));

  int x = n + rem * 2;
  int need = lagbe - x;

  return need >= 0 and rem * 2 <= nn;
}

int f(int row) {
  if (row > m) return -1;

  int col = (m - row) / row;
  int lagbe = col - row;
  int rem = (m - row) % row;

  if (lagbe == n + rem * 2 and rem * 2 <= nn) return col;

  // cout << ok(3, 1) << '\n';

  int l = 1, r = col, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid, row)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }

  col = ans;
  lagbe = col - row;
  rem = m - ((col + 1) * row);
  if (lagbe == n + rem * 2 and rem * 2 <= nn) return col;

  return -1;
}

void solve() {
  cin >> n >> m;
  nn = n;

  m += n / 2;
  n &= 1;

  for (int i = 1; i * i <= 2 * max(n, m); i++) {
    int x = f(i);
    if (x != -1) {
      cout << i << ' ' << x << '\n';
      return;
    }
    // return;
  }


  cout << -1 << '\n';
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