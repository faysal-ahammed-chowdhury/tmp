#include<bits/stdc++.h>
using namespace std;
#define ll long long


int n, m;
const int N = 505;
const ll inf = 1e18;
int src[N];
int g[N][N];
ll dis[N][N];

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
int main(){
    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        g[u][v] = (g[u][v] != 0 ? min(g[u][v], w) : w);
        g[v][u] = (g[v][u] != 0 ? min(g[v][u], w) : w);
    }
    floyd_warshall();

    int q; cin >> q;
    while ( q-- > 0 ){
        int k; cin >> k;
        ll ans = inf;
        for ( int i = 0; i < k; i++ ){
            int x; cin >> x;
            ans = min( ans, dis[1][x] + dis[x][n] );
        }
        cout << ans << endl;
    }
}