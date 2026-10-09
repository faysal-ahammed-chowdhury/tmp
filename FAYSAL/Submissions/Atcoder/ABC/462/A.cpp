#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (auto c : s) {
    if (c >= '0' and c <= '9') cout << c;
  }
  cout << '\n';

  return 0;
}