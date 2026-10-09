#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
ll dp[20][200][2];
 
int rec( string &s, ll i, ll sum, bool tight ){
 
    if ( i == 0 ) return dp[i][sum][tight] = sum;
    if ( dp[i][sum][tight] != -1 ) return dp[i][sum][tight];
 
    int ub = tight ? s[s.size()-i] - '0' : 9;
    int ans = 0;
    for ( int d = 0; d <= ub; d++ ){
        ans += rec( s, i-1, sum + d, ( tight ? (ub==d) : 0 ) );
    }
    return dp[i][sum][tight] = ans;
 
}
 
void tohka(){
 
    int a,b;    
 
    while ( 1 ){
 
        cin >> a >> b;
        if ( a == -1 && b == -1 ) break;
 
        if ( a == 0 ){
            string sb = to_string(b);
            memset(dp,-1,sizeof dp);
            cout << rec( sb, sb.size(), 0, 1 );
            continue;
        }
 
        a--;
 
        string sa = to_string(a); 
        string sb = to_string(b);
        
        memset(dp,-1,sizeof(dp) );
        int suma = rec( sa, sa.size(), 0, 1 );
        
        memset(dp,-1,sizeof(dp) );
        int sumb = rec( sb, sb.size(), 0, 1 );
 
        cout << sumb-suma << endl;
 
    }
 
 
}
 
signed main(){
    fast();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        tohka();
    }      
    return 0;
}    