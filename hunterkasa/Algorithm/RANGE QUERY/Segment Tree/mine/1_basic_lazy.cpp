#include<bits/stdc++.h>
using namespace std;

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




const int N = 2e5+5;
int a[N];
int t[4*N];
int lazy[4*N];

void push( int node, int b, int e ){
    if ( lazy[node] == -1 ) return; //////////////////////
    t[node] += lazy[node] * ( e - b + 1 );    //////////////////////

    int left_child = node << 1;
    int right_child = left_child | 1;
    if ( b != e ){
        lazy[left_child] = lazy[left_child] + lazy[node]; //////////////////////
        lazy[right_child] = lazy[right_child] + lazy[node]; //////////////////////
    }
    lazy[node] = -1; //////////////////////
}

void pull( int node ){
    t[node] = t[node<<1] + t[(node<<1) | 1]; 
}

void build( int n, int b, int e ){
    lazy[n] = -1; //////////////////////
    if ( b == e ){
        t[n] = a[b]; //////////////////////
        return;
    }
    int l = n<<1, r = n<<1|1;
    int mid = (b+e) / 2;
    build(l,b,mid);
    build(r,mid+1,e);
    pull(n);
}

void udp( int n, int b, int e, int i, int j, int x ){
    push(n,b,e);
    if ( b > j || e < i ) return;
    if ( b >= i && e <= j ){
        lazy[n] += x; //////////////////////
        push(n,b,e);
        return;
    }
    int l = n<<1, r = n<<1|1;
    int mid = (b+e) / 2;
    udp(l,b,mid,i,j,x);
    udp(r,mid+1,e,i,j,x);
    pull(n);
}

int query( int n, int b, int e, int l, int r ){
    push(n,b,e);
    if ( b > r || e < l ) return 0; //////////////////////
    if ( b >= l && e <= r ) return t[n]; //////////////////////
    int left_node = n << 1, right_node = n << 1 | 1, mid = ( b + e ) / 2;
    int x = query(left_node, b, mid, l, r);
    int y = query(right_node, mid+1, e, l, r); 
    return x + y; //////////////////////
}

void senritsu() {   
    
   

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