#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int cs;
void solve() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  if ((a == 0 and b > 0) or (c == 0 and d > 0) or (e == 0 and f > 0)) {
    cout << "Case " << ++cs << ": " << 1 << '\n';
    return;
  }

  int two = 0, five = 0;

  int cnt = 0;
  while (a > 0 and a % 5 == 0) {
    a /= 5;
    cnt++;
  }
  five += cnt * b;

  cnt = 0;
  while (c > 0 and c % 5 == 0) {
    c /= 5;
    cnt++;
  }
  five += cnt * d;

  cnt = 0;
  while (e > 0 and e % 5 == 0) {
    e /= 5;
    cnt++;
  }
  five += cnt * f;

  cnt = 0;
  while (a > 0 and a % 2 == 0) {
    a /= 2;
    cnt++;
  }
  two += cnt * b;

  cnt = 0;
  while (c > 0 and c % 2 == 0) {
    c /= 2;
    cnt++;
  }
  two += cnt * d;

  cnt = 0;
  while (e > 0 and e % 2 == 0) {
    e /= 2;
    cnt++;
  }
  two += cnt * f;

  cout << "Case " << ++cs << ": " << min(two, five) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
