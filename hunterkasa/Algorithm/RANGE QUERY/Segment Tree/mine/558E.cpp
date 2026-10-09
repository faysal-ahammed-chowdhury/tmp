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




const int N = 1e5+5;
int a[N];
int t[26][4*N];
int lazy[26][4*N];

void pull( int idx, int node ){
    t[idx][node] = t[idx][node<<1] + t[idx][(node<<1) | 1]; 
}

void push( int idx, int node, int b, int e ){
    if ( lazy[idx][node] == -1 ) return;
    
    t[idx][node] = lazy[idx][node] * ( e - b + 1 );
    int left_child = node << 1;
    int right_child = left_child | 1;
    
    if ( b != e ){
        lazy[idx][left_child] = lazy[idx][node];
        lazy[idx][right_child] = lazy[idx][node];
    }
    lazy[idx][node] = -1;
}

void build( int idx, int n, int b, int e ){
    if ( b == e ){
        t[idx][n] = 1;
        return;
    }
    int l = n<<1, r = n<<1|1;
    int mid = (b+e) / 2;
    build(idx,l,b,mid);
    build(idx,r,mid+1,e);
    pull(idx,n);
}

void udp( int idx, int n, int b, int e, int i, int j, int val ){
    push(idx,n,b,e);
    if ( b > j || e < i ) return;
    if ( b >= i && e <= j ){
        lazy[idx][n] = val;
        push(idx,n,b,e);
        return;
    }
    int l = n<<1, r = n<<1|1;
    int mid = (b+e) / 2;
    udp(idx,l,b,mid,i,j,val);
    udp(idx,r,mid+1,e,i,j,val);
    pull(idx,n);
}

int query( int idx, int n, int b, int e, int l, int r ){
    push(idx,n,b,e);
    if ( b > r || e < l ) return 0;
    if ( b >= l && e <= r ) return t[idx][n];
    int left_node = n << 1, right_node = n << 1 | 1, mid = ( b + e ) / 2;
    int x = query(idx,left_node, b, mid, l, r);
    int y = query(idx,right_node, mid+1, e, l, r); 
    return x + y;
}

void senritsu() {   
    
    memset(lazy,-1,sizeof lazy);

    int n, q; cin >> n >> q;
    string s; cin >> s;

    for ( int i = 1; i <= n; i++ ) udp( s[i-1]-'a', 1, 1, n, i, i, 1 );

    while ( q-- > 0 ){
        int l, r, k; cin >> l >> r >> k;
        int idx = l;
        if ( k == 0 ){
            for ( int i = 25; i >= 0; i-- ){
                int x = query(i,1,1,n,l,r);
                if ( x > 0 ){
                    udp(i,1,1,n,l,r,0);
                    udp(i,1,1,n,idx,idx+x-1,1);
                    idx += x;
                }
            }
        } else {
            for ( int i = 0; i <= 25; i++ ){
                int x = query(i,1,1,n,l,r);
                if ( x > 0 ){
                    udp(i,1,1,n,l,r,0);
                    udp(i,1,1,n,idx,idx+x-1,1);
                    idx += x;
                }
            }
        }
    }

    for ( int i = 1; i <= n; i++ ){
        for ( int j = 0; j <= 25; j++ ){
            if ( query(j,1,1,n,i,i) ){
                cout << char('a'+j);
                break;
            }
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