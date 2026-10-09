#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 305, inf = 1e18;
int g[N][N];
int dis[N][N];
int n, k;

void floyd_warshall() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) dis[i][j] = 0;
      else if (g[i][j] == 0) dis[i][j] = inf;
      else dis[i][j] = g[i][j];
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dis[i][k] < inf and dis[k][j] < inf)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

int32_t main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int w; cin >> w;
      g[i][j] = (g[i][j] != 0 ? min(g[i][j], w) : w);
      g[j][i] = (g[j][i] != 0 ? min(g[j][i], w) : w);
    }
  }

  floyd_warshall();

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += dis[i][j];
    }
  }

  cin >> k;
  for (int tmp = 1; tmp <= k; tmp++) {
    int u, v, w; cin >> u >> v >> w;
    if (dis[u][v] <= w) {
      cout << ans << ' ';
      continue;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int a = dis[i][u], b = dis[j][v];
        int now = a + b + w;
        if (now <= dis[i][j]) {
          // if (tmp == 2) {
          //   cout << "here: " << i << ' ' << j << ' ' << dis[i][j] << ' ' << now << '\n';
          // }
          ans -= dis[i][j];
          ans += now;
          dis[i][j] = now;
          dis[j][i] = now;
        }
      }
    }

    cout << ans << ' ';
  }
  cout << '\n';

  return 0;
}
