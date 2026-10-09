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



const int N = 2e5+10;
int a[N];

struct node{
    int mx, pre, suf, ans, sum;
    node( int val = -1e17 ){
        mx = val;
        pre = val;
        suf = val;
        sum = val;
        ans = val;
    }
};

node combine( node &l, node &r ){
    if (l.sum == -1e15) return r; 
    if (r.sum == -1e15) return l; 

    node res;
    res.sum = l.sum + r.sum;
    res.pre = max( l.pre, l.sum + r.pre );
    res.suf = max( r.suf, r.sum + l.suf );
    res.ans = max({ l.ans, r.ans, l.suf + r.pre });
    res.mx = max({ l.mx, r.mx });
    return res;
}

struct ST {
    node t[4 * N]{};
    ST() { memset(t, 0, sizeof t); }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = node(a[b]);
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = combine(t[l], t[r]);
    }
    node query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return node();
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        node L = query(l, b, mid, i, j);
        node R = query(r, mid + 1, e, i, j);
        return combine(L, R);
    }
    void upd( int n, int b, int e, int i, int x ){
        if ( b > i || e < i ) return;
        if ( b == i && e == i ) {
            t[n] = node(x);
            return;
        }
        int mid = (b+e)>>1, l = n << 1, r = l|1;
        upd(l,b,mid,i,x);
        upd(r,mid+1,e,i,x);
        t[n] = combine(t[l], t[r]);
    }
}st;

void senritsu() {   

    int n; cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];

    st.build(1,1,n);

    int lft[n+1]{}, rt[n+1]{};
    {
        stack<int> st;
        for ( int i = 1; i <= n; i++ ){
            while ( !st.empty() && a[st.top()] <= a[i] ) st.pop();
            lft[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
    }
    {
        stack<int> st1;
        for ( int i = n; i >= 1; i-- ){
            while ( !st1.empty() && a[st1.top()] <= a[i] ) st1.pop();
            rt[i] = st1.empty() ? n+1 : st1.top();
            st1.push(i);
        }
    }

    int ok = 1;
    
    for ( int i = 1; i <= n; i++ ){
        node x = st.query(1,1,n,lft[i]+1,rt[i]-1);
        ok &= ( x.mx >= x.ans );
    }

    cout << ( ok ? "YES" : "NO" ) << endl;
    
}

signed main() {
    Wah();
    int tt = 1;
    cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}