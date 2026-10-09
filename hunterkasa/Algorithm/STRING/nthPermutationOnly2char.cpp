#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debuga(a, n)
#endif
 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'
 
void Wah(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freqopen("output.txt","w",stdout);
    #endif
}
 
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
// #define int long long
 








long long int dp[31][31];
void pre(){
    dp[0][0] = 1;
    for ( int i = 0; i < 31; i++ ){
        for ( int j = 0; j < 31; j++ ){
            if ( i != 0 ) dp[i][j] += dp[i-1][j];
            if ( j != 0 ) dp[i][j] += dp[i][j-1];
        }
    }
}

string rec( long long int a, long long int b, long long int n ){
    if ( a == 0 ) return string(b,'b');
    if ( b == 0 ) return string(a,'a');

    if ( n <= dp[a-1][b] ){
        return "a" + rec(a-1,b,n);
    } else {
        return "b" + rec(a,b-1,n-dp[a-1][b]);
    }
}

void AmeDoko(){

    long long int a,b,n; cin >> a >> b >> n;

    cout << rec(a,b,n) << endl;

}   
 
signed main(){
    pre();
    Wah();
    int tt = 1;
    // cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        AmeDoko();
    }      
    return 0;
}         