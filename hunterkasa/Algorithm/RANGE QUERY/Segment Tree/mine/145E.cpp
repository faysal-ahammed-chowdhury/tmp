// https://codeforces.com/problemset/problem/145/E
#include<bits/stdc++.h>
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
typedef pair<int,int> pii;



struct VAL{
    int even, odd, ans, rans;
};

const int N = 1e6+5;
int a[N];
VAL t[4*N];
int lazy[4*N];

VAL merge( VAL &l, VAL &r ){
    VAL res;
    res.even = l.even + r.even;
    res.odd = l.odd + r.odd;
    res.ans = max( l.even + r.ans, l.ans + r.odd );
    res.rans = max( l.odd + r.rans, l.rans + r.even );
    return res;
}

void pull( int node ){
    t[node] = merge(t[node<<1], t[(node<<1) | 1]); 
}

void push( int node, int b, int e ){
    if ( !lazy[node] ) return;

    if ( lazy[node] % 2 == 1 ){
        swap(t[node].even,t[node].odd);
        swap(t[node].ans,t[node].rans);
    }

    int left_child = node << 1;
    int right_child = left_child | 1;
    if ( b != e ){
        lazy[left_child] = lazy[left_child] + lazy[node];
        lazy[right_child] = lazy[right_child] + lazy[node];
    }
    lazy[node] = 0;
}


void build( int n, int b, int e ){
    if ( b == e ){
        t[n] = { a[b] == 4, a[b] == 7, 1, 1 };
        return;
    }
    int l = n<<1, r = n<<1|1;
    int mid = (b+e) / 2;
    build(l,b,mid);
    build(r,mid+1,e);
    pull(n);
}

void udp( int n, int b, int e, int i, int j ){
    push(n,b,e);
    if ( b > j || e < i ) return;
    if ( b >= i && e <= j ){
        lazy[n] += 1;
        push(n,b,e);
        return;
    }
    int l = n<<1, r = n<<1|1;
    int mid = (b+e) / 2;
    udp(l,b,mid,i,j);
    udp(r,mid+1,e,i,j);
    pull(n);
}

void senritsu() {   
    
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for ( int i = 1; i <= n; i++ ) a[i] = s[i-1] - '0';

    build(1,1,n);

    while ( q-- > 0 ){
        cin >> s;
        if ( s == "count" ){
            cout << t[1].ans << endl;
        } else {
            int l, r; cin >> l >> r;
            udp(1,1,n,l,r);
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