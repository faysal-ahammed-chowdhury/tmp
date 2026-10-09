#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            "\n"
 
void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
// #define int long long
 

// google kickstart 2020 boring numbers
ll dp[20][2][2][2];
ll rec( string &s, int d, bool even, bool leading, bool tight ){
    if ( d == 0 ) return 1;
    if ( dp[d][even][leading][tight] != -1 ) return dp[d][even][leading][tight];
    int ub = tight ? s[s.size()-d] - '0': 9;
    ll ans = 0;
    if ( even ){
        for ( int i = 0; i <= 8; i += 2 )
            if ( i <= ub )
                ans += rec( s, d-1, 0, 0, tight & ( i == ub ) );
    } else {
        if ( leading ){
            ans += rec( s, d-1, 0, 1, 0 );
        }
        for ( int i = 1; i <= 9; i += 2 )
            if ( i <= ub )
                ans += rec( s, d-1, 1, 0, tight & ( i == ub ) );
    }
    return dp[d][even][leading][tight] = ans;
}

void tohka(){

    string L,R;
    ll l, r; cin >> l >> r; l--;
    L = to_string(l);
    R = to_string(r);

    memset(dp,-1,sizeof dp);
    int ans1 = rec(R,R.size(),0,1,1);
    
    memset(dp,-1,sizeof dp);
    int ans2 = rec(L,L.size(),0,1,1);
    
    cout << ans1 - ans2 << endl;

}
 
signed main(){
    fast(); 
    ll tt = 1;
    cin >> tt;
    while ( tt-- > 0 ){
        tohka();
    }      
    return 0;
}