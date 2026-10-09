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



vector<int> a;
const int N = 11;
int dp[N][2];

int rec( int pos, int tight, int val ){
    if ( pos >= a.size() ) return 0;
    int &ret = dp[pos][tight];
    if ( ~ret ) return ret;

    ret = 0;
    int ub  = tight ? a[pos] : 9;
    
    for ( int i = 0; i <= ub; i++ ){
        ret = max( ret, rec(pos+1, (tight & ( i == ub )), val ) + ( i == val ) );
    }
    return ret;
}

void senritsu() {   

    int n; cin >> n;
    while ( n ){
        a.push_back(n%10);
        n /= 10;
    }
    reverse(a.begin(),a.end());

    int ans = 0;
    for ( int i = 0; i <= 9; i++ ){
        memset(dp,-1,sizeof dp);
        int x = rec( 0, 1, i );
        ans += x;
    }
    cout << max( ans - 1, 0ll ) << endl;

}

signed main() {
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}