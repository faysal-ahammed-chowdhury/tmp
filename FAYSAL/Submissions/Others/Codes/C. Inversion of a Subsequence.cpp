#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int cnt = 0;
  bool flag = false;
  bool ase1 = false;
  bool ase2 = false;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1 and b[i] == 0) cnt++;
    else if (a[i] == 0 and b[i] == 1) flag = true;
    else if (a[i] == 1 and b[i] == 1) ase1 = true;
    else if (a[i] == 0 and b[i] == 0) ase2 = true;
  }

  if (cnt == 0 and flag) {
    if (ase1 and ase2) cout << "2\n";
    else cout << "-1\n";
  }
  else if (cnt == 0 and flag == false) cout << "0\n";
  else if (cnt & 1) cout << "1\n";
  else cout << "2\n";
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