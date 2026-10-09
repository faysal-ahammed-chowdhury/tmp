#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int __int128

const ll N = 2e5 + 9;
ll n, k, a[N];

bool ok(int mn) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int need = mn - a[i];
    if (need <= 0) continue;
    cnt += (need + i - 1) / i;
  }

  return cnt <= k;
}

void print(int x) {
  string s = "";
  while (x > 0) {
    int last = x % 10;
    s += char(last + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = 1e30, ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  print(ans);

  return 0;
}