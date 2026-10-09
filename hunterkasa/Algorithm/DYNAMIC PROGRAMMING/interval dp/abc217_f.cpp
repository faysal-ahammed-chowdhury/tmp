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


const int p = 998244353;
int choose[1010][1010];

void calc(){
    for ( int i = 0; i < 1010; i++ ) choose[i][0] = 1, choose[i][i] = 1;
    for ( int i = 1; i < 1010; i++ ){
        for ( int j = 1; j < 1010; j++ ){
            choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % p;
        }
    }
}

const int MOD = 998244353;
inline int add( int x, int y ) { return ( ( x + y ) % MOD + MOD) % MOD; }
inline int mul( int x, int y ){ return x * 1ll * y % MOD; }
inline int binpow( int x, int y ) { int z = 1; while( y ){ if( y % 2 == 1 ) z = mul( z, x );x = mul( x, x ); y /= 2; } return z; }
inline int inv( int x ){ return binpow( x, MOD - 2 ); }
inline int divide( int x, int y ){ return mul( x, inv( y ) ); }

const int M = 505;
int dp[M][M];
int n, m; 
bool mp[M][M];


int rec( int l, int r ){

    if ( l > r ) return 1;

    int &ret = dp[l][r];
    if ( ~ret ) return ret;

    ret = 0;
    for ( int i = l+1; i <= r; i++ ){
        if ( mp[l][i] ){
            int x = mul( rec( l+1, i-1 ), rec( i+1, r ) );
            x = mul( x, choose[ ( r - l + 1 ) / 2 ][ ( i - l + 1 ) / 2 ] );
            ret = add( x, ret );
        }
    }
    return ret;

}

void senritsu() {   

    calc();

    cin >> n >> m;
    n *= 2;
    for ( int i = 0; i < m; i++ ){
        int x, y; cin >> x >> y;
        mp[x][y] = 1;
        mp[y][x] = 1;
    }

    memset(dp,-1,sizeof dp);

    cout << rec( 1, n ) << endl;

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