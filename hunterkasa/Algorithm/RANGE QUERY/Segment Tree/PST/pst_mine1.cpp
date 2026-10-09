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
};

map<int,int> mp,mp1;
const int N = 1e5+10;
int a[N];
int val[N], tin[N], tout[N];
int timer = 0;
vll g[N];
node *roots[N];

node *build( int start, int end ){
    node *cur = new node();
    if ( start == end ){
        cur->l = NULL;
        cur->r = NULL;
        cur->cnt = 0;
        return cur;
    }
    int mid = ( start + end ) / 2;
    cur->l = build(start, mid);
    cur->r = build(mid+1, end);
    cur->cnt = cur->l->cnt + cur->r->cnt;
    return cur;
}

node *update( node *prev, int start, int end, int idx ){
    node *cur = new node();
    if ( start == end ){
        cur->cnt = prev->cnt + 1;
        cur->l = NULL;
        cur->r = NULL;
        return cur;
    }
    int mid = ( start + end ) / 2;
    if ( idx <= mid ){
        cur->l = update( prev->l, start, mid, idx );
        cur->r = prev->r;
    } else {
        cur->l = prev->l;
        cur->r = update( prev->r, mid+1, end, idx );
    }
    cur -> cnt = cur->l->cnt + cur->r->cnt;
    return cur;
}

int query( node *nodeR, node *nodeL, int start, int end, int k ){
    if ( start == end ) return start;
    int mid = ( start + end ) / 2;
    int count_right = nodeR->r->cnt - nodeL->r->cnt;
    if ( count_right >= k )
        return query(nodeR->r, nodeL->r, mid+1, end, k);
    else
        return query(nodeR->l, nodeL->l, start, mid, k - count_right);
}

void dfs( int x, int p ){
    tin[x] = ++timer;
    val[timer] = mp[a[x]];
    for ( auto c : g[x] ){
        if ( c == p ) continue;
        dfs(c,x);
    }
    tout[x] = timer;
}

void senritsu() {   

    int n, q; cin >> n >> q;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];

    set<int> st(a+1,a+n+1);
    int cnt = 1;
    for ( auto c : st ){
        mp[c] = cnt;
        mp1[cnt] = c;
        cnt++;
    }
    cnt -= 1;

    for ( int i = 0; i < n-1; i++ ){
        int x, y ; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1,0);

    roots[0] = build(1,cnt);
    for ( int i = 1; i <= n; i++ ){
        roots[i] = update(roots[i-1], 1, cnt, val[i]);
    }

    while ( q-- > 0 ){
        int v,k; cin >> v >> k;
        int idx = query(roots[tout[v]], roots[tin[v]-1], 1, cnt, k);

        cout << mp1[idx] << endl;
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
