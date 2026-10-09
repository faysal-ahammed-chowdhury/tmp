#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debuga(a, n)
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
 
// typedef vector<long long> vll;
// typedef long long ll;
// typedef long double ld;
// #define int long long
 
// #define inf 0x3f3f3f3f3f3f3f3fLL
 
 
int n, x;
const int N = 101;
int h[N], s[N], k[N];
const int X = 1e5+10;
int dp[X];
 
void senritsu() {   
 
    cin >> n >> x;
    for ( int i = 1; i <= n; i++ ) cin >> h[i];
    for ( int i = 1; i <= n; i++ ) cin >> s[i];
    for ( int i = 1; i <= n; i++ ) cin >> k[i];
 
    for ( int i = 0; i < X; i++ ) dp[i] = INT_MIN;
 
    dp[0] = 0;
    for ( int i = 1; i <= n; i++ ){
 
        for ( int j = 0; j <= 10 && k[i]; j++ ){
 
            int cnt = min( (1 << j), k[i] );
            int weight = cnt * h[i];
            int value  = cnt * s[i];
 
            for (int wt = x; wt >= weight; wt--) {
                if (dp[wt - weight] != INT_MIN)
                    dp[wt] = max(dp[wt], dp[wt - weight] + value);
            }
            
            k[i] -= cnt;
 
        }
 
    }
 
    int ans = 0;
    for ( int i = 0; i <= x; i++ ) ans = max( ans, dp[i] );
    cout << ans << endl;
 
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