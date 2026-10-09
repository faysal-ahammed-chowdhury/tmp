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
 
 
 
#define int long long

string r;
int dp[20][200][2];

int rec( string &num, int n, int x, bool tight ){
    if ( n == 1 ){
        if ( tight && x >= 0 && x <= ( num[num.size()-n]-'0' ) ) return 1;
        else if ( !tight && x >= 0 && x <= 9 ) return 1;
        else return 0;
    }

    if ( dp[n][x][tight] != -1 ) return dp[n][x][tight];

    dp[n][x][tight] = 0;

    int ub  = tight ? ( num[num.size()-n] - '0' ) : 9;

    for ( int i = 0; i <= ub; i++ ){
        dp[n][x][tight] += rec( num, n-1, x-i, (tight & ( i == ub ) ) );
    } 

    return dp[n][x][tight];

}
 
void tohka(){

    string n = "1120343423443535";
    memset(dp, -1, sizeof dp);
    cout << rec( n, n.size(), 150, 1 ) << endl;
    
}
 
signed main(){
    fast(); 
    ll tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        tohka();
    }      
    return 0;
}
