#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 4005;
int n, a, pref[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a;
  string s; cin >> s;
  n = s.size();
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] - '0');
  }

  map<int, int> mp;

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int x = pref[j] - pref[i - 1];
      mp[x]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int x = pref[j] - pref[i - 1];
      if (x == 0) {
        if (a == 0) ans += (n * (n + 1)) / 2;
        continue;
      }
      if (a % x != 0) continue;
      int y = a / x;
      ans += mp[y];
    }
  }

  cout << ans << '\n';

  return 0;
}