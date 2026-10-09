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
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
// #define int long long
 



string s;
int n;
int cnt[30];
ll dp[32][32];
void pre(){
    for(int i=0; i<=20; i++) {
        dp[i][0]=1;
        dp[i][i]=1;
        for(int j=1; j<=i; j++){
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
}

ll calc( int pos ){
    ll ret = 1;
    for ( int i = 0; i < 26; i++ ) {
        ret *= dp[pos][cnt[i]];
        pos -= cnt[i];
    }
    return ret;
}

void rec( int pos, ll k ){

    if ( pos >= n ) return;

    int i;
    for ( i = 0; i < 26; i++ ){
        if ( !cnt[i] ) continue;

        cnt[i]--;
        ll now = calc(n-pos-1);

        if ( now >= k ) break;

        cnt[i]++;
        k -= now;
    }
    cout << char(i+'a');

    rec(pos+1, k);

}

void AmeDoko(){

    memset(cnt, 0, sizeof cnt);

    long long k;      
    cin >> s >> k;

    n = s.size();

    for ( auto c : s ) cnt[c-'a']++;

    

    // ll all = 1;
    // for ( int i = 2; i <= n; i++ ) all *= i;
    // for ( int i = 0; i < 26; i++ ){
    //     if ( !cnt[i] ) continue;
    //     ll x = 1;
    //     for ( int j = 2; j <= cnt[i]; j++ ) x *= j;
    //     all /= x;
    // }

    if ( calc(n) < k ){
        cout << "Impossible" << endl;
        return;
    }

    rec( 0, k );
    cout << endl;

}   
 
signed main(){
    pre();
    Wah();
    int tt = 1;
    cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ": ";
        AmeDoko();
    }      
    return 0;
}         