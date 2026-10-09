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
        freopen("output.txt","w",stdout);
    #endif
}

typedef vector<long long> vll;
typedef long double ld;
#define int long long



// they need 100k's and 1000k's of gpu's to mimic this ? 


const int N = 2e5+10;
int a[N];
struct ST {
    int t[4 * N]{};
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[e];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = max(t[l], t[r]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] -= x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = max(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j, int x) {
        if (b > j || e < i || t[n] < x) return -1;
        if ( b == e ) return b;
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;

        int L = query(l, b, mid, i, j, x);
        if ( L != -1 ) return L;
        return query(r, mid + 1, e, i, j, x);
    }
}st;


void senritsu() {   

    int n, q; cin >> n >> q;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];

    st.build(1,1,n);

    while ( q-- > 0 ){
        int x; cin >> x;
        int v = st.query(1,1,n,1,n,x);
        if ( v == -1 ) cout << 0 << ' ';
        else {
            cout << v << ' ';
            st.upd(1,1,n,v,x);
        }
    }

    
}


signed main() {
    Wah();
    int tt = 1;
    // cin >> tt;
    int i = 1;
    while ( tt-- > 0 ) {
        // cout << "Case #"<< i++ << ": ";
        senritsu();
    }
    return 0;
}