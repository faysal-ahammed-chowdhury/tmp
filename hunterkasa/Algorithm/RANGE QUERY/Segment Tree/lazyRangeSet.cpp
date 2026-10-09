#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debuga(a, n)
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





const int N = 1e5 + 9;
int A[N], B[N];
struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    bool mark[4 * N];
    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
        memset(mark, 0, sizeof mark);
    }
    inline void push(int n, int b, int e) {
        if (!mark[n]) return;
        t[n] = (e - b + 1) * lazy[n];
        if (b != e) {
            lazy[lc] = lazy[n];
            lazy[rc] = lazy[n];
            mark[lc] = mark[rc] = true;
        }
        mark[n] = false;
    }
    inline long long combine(long long a,long long b) {
        return a + b;
    }
    inline void pull(int n) {
        t[n] = t[lc] + t[rc];
    }
    void build(int n, int b, int e) {
        mark[n] = 0;
        if (b == e) {
            t[n] = 0;
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
            lazy[n] = v; //set lazy
            mark[n] = 1;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j) return 0; //return null
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} st;

void senritsu(){

    int n, q; cin >> n >> q;
    for ( int i = 1; i <= n; i++ ) cin >> A[i];
    for ( int i = 1; i <= n; i++ ) cin >> B[i];

    struct val{ int x,y,k; };
    vector<val> Q(q+1);
    for ( int i = 1; i <= q; i++ ){
        int t; cin >> t;
        if ( t == 2 ){
            int id; cin >> id;
            int v = st.query(1,1,n,id,id);
            if ( v == 0 ){
                cout << B[id] << endl;
            } else {
                int x = Q[v].x;
                int y = Q[v].y;
                int k = Q[v].k;
                int dif = id - y;
                cout << A[x + dif] << endl;
            }
        } else {
            int x,y,k; cin >> x >> y >> k;
            Q[i] = {x,y,k};
            st.upd(1,1,n,y,y+k-1,i);
        }
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