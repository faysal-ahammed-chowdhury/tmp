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



struct node{
    node *l, *r;
    int cnt = 0;
    // int val = 0;
};

const int NMAX = 20000+10;

node *build( int start, int end ){

    if ( start == end ){
        node *cur = new node();
        cur->l = NULL;
        cur->r = NULL;
        // cur->val = 0;
        cur->cnt = 0;
        return cur;
    }

    int mid = ( start + end ) / 2;
    node *cur = new node();
    cur->l = build( start, mid );
    cur->r = build( mid+1, end );
    cur->cnt = cur->l->cnt + cur->r->cnt;
    // cur->val = cur->l->val + cur->r->val;
    return cur;

}

node *update( node *root, int start, int end, int i, int x ){

    if ( start == i && end == i ){
        node *cur = new node();
        cur->cnt = 1 + root->cnt;
        // cur->val = x;
        return cur;
    }

    int mid = ( start + end ) / 2;
    node *cur = new node();

    if ( mid >= i ){
        cur->l = update(root->l, start, mid, i, x);
        cur->r = root->r;
    } else {
        cur->l = root->l;
        cur->r = update(root->r, mid+1, end, i, x );
    }
    cur->cnt = cur->l->cnt + cur->r->cnt;
    // cur->val = cur->l->val + cur->r->val;

    return cur;

}

int query( node *u, node *v, node *l, int start, int end, int k ) {
    
    if ( end <= k ) return 0;
    if ( start > k ) return u->cnt + v->cnt - 2*l->cnt;

    int mid = ( start + end ) / 2;
    return query( u->l, v->l, l->l, start, mid, k ) + query( u->r, v->r, l->r, mid + 1, end, k );

}


const int N = 1e5+10, LOG_MAX = 20;
vector<pair<int,int>> g[N];
int n, q, par[N][20], dep[N]; 
node* roots[N];


void dfs( int x, int p ){
    node *v;
    par[x][0] = p;
    for ( int i = 1; i < LOG_MAX; i++ ) par[x][i] = par[par[x][i-1]][i-1];
    for ( auto [c,w] : g[x] ){
        if ( c == p ) continue;
        dep[c] = dep[x] + 1;
        v = update( roots[x], 1, NMAX, w, 1 );
        roots[c] = v;
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

    cin >> n >> q;
    for ( int i = 0; i < n-1; i++ ){
        int x,y,w; cin >> x >> y >> w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }

    roots[0] = roots[1] = build(1,NMAX);

    dfs(1,0);

    const int mx = 20000;
    while ( q-- > 0 ){
        int u, v, t; cin >> u >> v >> t;
        int l = lca(u,v);

        int ans = 0;
        int cur = t;
        while ( cur < mx ){
            int x = query( roots[u], roots[v], roots[l], 1, NMAX, cur );
            if ( x == 0 ) break;
            ans += x;
            cur += t;
        }
        cout << ans + dist(u,v) + 1 << endl;
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