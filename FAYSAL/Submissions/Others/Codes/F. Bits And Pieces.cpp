#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLR(int &N, int pos) { (N &= ~(1 << pos)); }

const int N = 1e6 + 9, MAX = (1 << 21), K = 22, mod = 1000000007;
int n, a[N];
pair<int, int> dp[MAX][2];
vector<int> idx[MAX];

int Mod(int x) {
  x %= 2;
  if (x < 0) x += 2;
  return x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]].push_back(i);
  }

  for (int bit = 0; bit < K; bit++) {
    for (int x = MAX - 1; x >= 0; x--) {
      if (bit == 0) {
        if (idx[x].size() >= 2) dp[x][Mod(bit)] = {idx[x][idx[x].size() - 2], idx[x].back()};
        if (idx[x].size() == 1) dp[x][Mod(bit)] = { -1, idx[x].back()};
        continue;
      }
      pair<int, int> &ans = dp[x][Mod(bit)];
      auto p1 = dp[x][Mod(bit - 1)];
      pair<int, int> p2 = { -1, -1};
      if (!CHECK(x, bit - 1)) {
        int y = x;
        SET(y, bit - 1);
        if (y < MAX) {
          p2 = dp[y][Mod(bit - 1)];
        }
      }

      int xx = p1.first;
      int y = p1.second;
      int z = p2.first;
      int zz = p2.second;

      int mx1 = max({xx, y, z, zz});

      int mx2 = max({
        xx == mx1 ? -1 : xx,
        y == mx1 ? -1 : y,
        z == mx1 ? -1 : z,
        zz == mx1 ? -1 : zz
      });

      ans = {mx2, mx1};
    }
  }

  int ans = 0;
  for (int i = 1; i + 2 <= n; i++) {
    int x = a[i];
    int y = 0;
    for (int k = K - 2; k >= 0; k--) {
      if (CHECK(x, k) == false) {
        SET(y, k);
        if (y < MAX and dp[y][Mod(K - 1)].first <= i) CLR(y, k);
      }
    }
    // cout << y << ' ' << dp[y][Mod(K - 1)].first << '\n';

    ans = max(ans, (x | y));
  }

  cout << ans << '\n';

  return 0;
}