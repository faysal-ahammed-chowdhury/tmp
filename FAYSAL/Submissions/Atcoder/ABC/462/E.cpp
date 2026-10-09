#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int f(int x, int y, int a, int b) {
  int mn = min(x, y);
  int ans = mn * 2 * min(a, b);

  if (x > mn) {
    int need = x - mn;
    int op1 = (need / 2) * (a + b);
    if (need & 1) op1 += a;

    int op2 = (need * 2 * b);
    if (need & 1) op2 += b;

    int op3 = (need * 2 * a);
    if (need & 1) op3 -= a;

    ans += min(op1, min(op2, op3));
  }
  else if (y > mn) {
    int need = y - mn;
    int op1 = (need / 2) * (a + b);
    if (need & 1) op1 += b;

    int op2 = (need * 2 * a);
    if (need & 1) op2 += a;

    int op3 = (need * 2 * b);
    if (need & 1) op3 -= b;

    ans += min(op1, min(op2, op3));
  }

  return ans;
}

void solve() {
  int x, y, a, b; cin >>  a >> b >> x >> y;
  x = abs(x);
  y = abs(y);

  cout << f(x, y, a, b) << '\n';
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