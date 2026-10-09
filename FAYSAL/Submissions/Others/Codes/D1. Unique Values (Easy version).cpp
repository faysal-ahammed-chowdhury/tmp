#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
int n;

bool ok(int mid) {
  int cnt = n - mid + 1;
  cout << "? " << cnt << ' ';
  for (int i = mid; i <= n; i++) {
    cout << i << ' ';
  }
  cout << endl;
  int ans; cin >> ans;

  return (cnt % 2) != (ans % 2);
}

bool ok2(int mid) {
  int cnt = mid;
  cout << "? " << cnt << ' ';
  for (int i = 1; i <= mid; i++) {
    cout << i << ' ';
  }
  cout << endl;
  int ans; cin >> ans;

  return (cnt % 2) != (ans % 2);
}

bool ok3(int mid, int st, int en) {
  int cnt = mid - st + 2;
  cout << "? " << cnt << ' ';
  for (int i = st; i <= mid; i++) {
    cout << i << ' ';
  }
  cout << en << endl;
  int ans; cin >> ans;

  return (cnt % 2) != (ans % 2);
}

void solve() {
  cin >> n;
  n = 2 * n + 1;

  int l = 1, r = n, first = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      first = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  l = 1, r = n;
  int last = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok2(mid)) {
      last = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  l = first + 1, r = last - 1;
  int middle = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok3(mid, first, last)) {
      middle = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  cout << "! " << first << ' ' << middle << ' ' << last << endl;
}

int32_t main() {
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}