#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d; cin >> a >> b >> c >> d;
  int e, f, g, h; cin >> e >> f >> g >> h;

  cout << (a * e) + (b * g) << ' ' << (a * f) + (b * h) << '\n';
  cout << (c * e) + (d * g) << ' ' << (c * f) + (d * h) << '\n';

  return 0;
}