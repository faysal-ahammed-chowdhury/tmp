#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugArr(arr, n)
#endif

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void Wah(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
#define int long long









const int N = 3e5 + 9, LG = 20;
vector<pair<int,int>> g[N];
int par[N][LG + 1], dep[N], sz[N];
int mn[N][LG+1];

void dfs( int u, int p ) {
    sz[u] = 1;
    for (int i = 1; i < LG; i++){
        par[u][i] = par[par[u][i - 1]][i - 1];
        mn[u][i] = min( mn[par[u][i-1]][i-1], mn[u][i-1] );
    }
    for (auto &[v, wt]: g[u]) {
        if ( v == p ) continue;
        mn[v][0] = wt;
        par[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
    return u;
}
int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}
int calc( int a, int b ){
    int lc = lca(a,b);
    int mn1 = 1e9, mn2 = 1e9;
    int k = dist(a,lc);
    if ( k ){
        k--;
        for ( int i = LG-1; i >= 0; i-- ){
            if ( ((k >> i) & 1) ){
                mn1 = min(mn1, mn[a][i]);
                a = par[a][i];
            }
        }
        mn1 = min(mn1, mn[a][0] );
    }
    k = dist(b,lc);
    if ( k ){
        k--;
        for ( int i = LG-1; i >= 0; i-- ){
            if ( (( k >> i ) & 1) ){
                mn2 = min( mn2, mn[b][i] );
                b = par[b][i];
            }
        }
        mn2 = min( mn2, mn[b][0] );
    }
    return min(mn1,mn2);
} 

void AmeDoko(){

    int n; cin >> n;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    int q; cin >> q;
    while ( q-- > 0 ) {
        int a,b;    cin >> a >> b;
        cout << calc(a,b) << endl;
    }

}   

signed main(){
    Wah();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        AmeDoko();
    }      
    return 0;
}        