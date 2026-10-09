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

typedef vector<long long> vll;
typedef long double ld;
#define int long long

#define inf 0x3f3f3f3f3f3f3f3fLL




struct items{
    int n, v, p;
};
struct truck{
    int c, f;
};
const int N = 5005;
int dp[N];
int odp[N];

void senritsu() {   
    
    int n, m; cin >> n >> m;
    items a[n+1]; for ( int i = 1; i <= n; i++ ) cin >> a[i].n >> a[i].v >> a[i].p;
    truck b[m+1]; for ( int i = 1; i <= m; i++ ) cin >> b[i].c >> b[i].f;

    for ( int i = 1; i <= n; i++ ){
        
        if ( a[i].v >= N ) continue;

        for ( int j = 0; j < N; j++ ) odp[j] = dp[j];

        for ( int j = 0; j < a[i].v; j++ ){

            deque<pair<int,int>> dq;

            for ( int k = 0; j + a[i].v * k < N; k++ ){

                int wt = j + a[i].v * k;

                int cost = odp[wt] - k * a[i].p;

                while ( !dq.empty() && dq.back().first <= cost ) dq.pop_back();

                dq.push_back({cost, k});

                while ( !dq.empty() && dq.front().second < k - a[i].n ) dq.pop_front();

                dp[wt] = max( dp[wt], dq.front().first + k * a[i].p );

            }

        }

    }

    int ans = INT_MIN;
    for ( int i = 1; i <= m; i++ ){
        ans = max( ans, dp[b[i].c] - b[i].f );
    }
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