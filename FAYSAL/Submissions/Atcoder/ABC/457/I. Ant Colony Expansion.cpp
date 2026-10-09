#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
set<int> a[25], b[25];

pair<int, int> query(int x, int y) {
  if (a[x].size() == 0 or b[y].size() == 0) return { -1, -1};
  cout << "? ";
  cout << a[x].size() << ' ';
  for (auto val : a[x]) {
    cout << val << ' ';
  }
  cout << b[y].size() << ' ';
  for (auto val : b[y]) {
    cout << val << ' ';
  }
  cout << endl;

  int p1, p2; cin >> p1 >> p2;
  return {p1, p2};
}

int32_t main() {

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x = (i % 20) + 1;
    a[x].insert(i);
    b[x].insert(i);
  }

  int ans[n + 1];
  memset(ans, -1, sizeof ans);

  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= 20; j++) {
      while (true) {
        auto [p1, p2] = query(i, j);
        if (p1 == -1) break;
        ans[p1] = p2;
        a[i].erase(p1);
      }
    }
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}