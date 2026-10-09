#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugA(a, n)
#endif

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'

void Wah() {
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt","w",stdout);
    #endif
}

typedef vector<long long> vll;
typedef long double ld;
#define int long long
#define ll long long



const int N = 2e5+10, LOG_MAX = 20;

int n; 
vll g[N];
int par[N][LOG_MAX], dep[N];

void dfs( int x, int p ){
    par[x][0] = p;

    for ( int i = 1; i < LOG_MAX; i++ ){
        par[x][i] = par[par[x][i-1]][i-1];
    }
    for ( auto c : g[x] ){
        if ( c == p ) continue;
        dep[c] = dep[x] + 1;
        dfs(c,x);
    }
}

int lca( int u, int v ){
    if ( dep[u] != dep[v] ){
        if ( dep[u] < dep[v] ) swap(u,v);
        int k = dep[u] - dep[v];
        for ( int i = 0; i < LOG_MAX; i++ ){
            if ( k >> i & 1 ){
                u = par[u][i];
            }
        }
    }
    if ( u == v ) return u;
    for ( int i = LOG_MAX-1; i >= 0; i-- ){
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}

void senritsu() {   

    cin >> n;
    int q = 1; cin >> q;
    for ( int i = 2; i <= n; i++ ){
        int x; cin >> x;
        g[x].push_back(i);
    }

    dfs(1,1);

    while ( q-- > 0 ){
        int u,v; cin >> u >> v;
        cout << lca(u,v) << endl;
    }

}

signed main() {
    Wah();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}