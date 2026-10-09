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
 
 
 
 

 







// count the number of digits that have the digit "d" fixed at even position 

const int mod = 1e9+7;
int moded, d;   
int dp[2010][2010][2];

int rec( string &s, int i, int val, bool tight ){

    if ( i == s.size() ){
        if ( val == 0 ) return 1;
        else return 0;
    }

    int &res = dp[i][val][tight];
    if ( res != -1 ) return res;

    res = 0;
    int ub = tight ? s[i]-'0' : 9;
    
    for ( int j = 0; j <= ub; j++ ){

        if ( i % 2 != 0 && j != d ) continue; 
        if ( i % 2 == 0 && j == d ) continue; 

        ll temp = (val*10+j) % moded;
        res = ((res % mod) + rec( s, i+1, temp , ( tight && j == ub ) ) % mod ) % mod;
    }

    return res;

}

void tohka(){

    cin >> moded >> d;
    string a,b;   cin >> a >> b;

    memset(dp, -1, sizeof dp);
    int sa = rec( a, 0, 0, 1 );

    memset(dp, -1, sizeof dp);
    ll sb = rec( b, 0, 0, 1 );

    bool ok = 1;
    ll sum = 0;
    for ( int i = 0; i < a.size(); i++ ){
        sum = (sum * 10) + a[i] - '0'; 
        sum %= moded;
        if ( i % 2 != 0 && a[i]-'0' == d ) continue;
        if ( i % 2 == 0 && a[i]-'0' != d ) continue;
        ok = 0;
    }
    ok = (ok & (sum == 0));
    
    cout << (sb - sa + ok + mod) % mod << endl;

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