#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 1e18;
int n, a[N];
int dp[N][2][2];

int f(int i, int cnt, int nisi) {
  if (i < 1) return 0;

  int &ans = dp[i][cnt][nisi];
  if (ans != -1) return ans;

  int x = a[i];
  if (cnt % 2 == 1) x = -x;
  ans = x + f(i - 1, cnt, nisi);
  if (x > 0) {
    ans = max(ans, -x + f(i - 1, (cnt + 1) % 2, true));
  }
  if (x < 0 and nisi == 1) {
    ans = max(ans, -x + f(i - 1, (cnt + 1) % 2, true));
  }

  // cout << i << ' ' << cnt << ' ' << x << ' ' << ans << '\n';

  return ans;
}


vector<int> v1, v2, v3;
void print(int i, int cnt, int nisi) {
  if (i < 1) return;

  int ans = f(i, cnt, nisi);

  int x = a[i];
  if (cnt % 2 == 1) x = -x;
  if (ans == x + f(i - 1, cnt, nisi)) {
    print(i - 1, cnt, nisi);
    return;
  }
  if (x > 0) {
    if (ans == -x + f(i - 1, (cnt + 1) % 2, true)) {
      v1.push_back(i);
      print(i - 1, (cnt + 1) % 2, true);
      return;
    }
  }

  if (x < 0 and nisi == 1) {
    if (ans == -x + f(i - 1, (cnt + 1) % 2, true)) {
      if (cnt == 1) {
        // cout << "x" << i << ' ';
        v2.push_back(i);
      }
      else {
        // cout << "y" << i << ' ';
        v3.push_back(i);
      }
      print(i - 1, (cnt + 1) % 2, true);
      return;
    }
  }

  // cout << i << ' ' << cnt << ' ' << x << ' ' << ans << '\n';

  return;
}

void solve() {
  v1.clear();
  v2.clear();
  v3.clear();

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][0][0] = dp[i][1][0] = -1;
    dp[i][0][1] = dp[i][1][1] = -1;
  }

  // cout << f(n, 0, false) << '\n';
  print(n, 0, false);

  reverse(v2.begin(), v2.end());
  reverse(v3.begin(), v3.end());

  cout << v1.size() + v2.size() + v3.size() << '\n';

  int j = 0;
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << ' ';
    while (j < v3.size() and v3[j] < v2[i]) {
      cout << v3[j] << ' ';
      j++;
    }
  }

  if (v1.size() > 0) cout << v1[0] << ' ';
  while (j < v3.size() and v3[j] < v1[0]) {
    cout << v3[j] << ' ';
    j++;
  }

  for (int i = 1; i < v1.size(); i++) {
    cout << v1[i] << ' ';
  }
  cout << '\n';
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