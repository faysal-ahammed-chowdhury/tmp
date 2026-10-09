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
#define int long long
 
 


vector<int> assignment;
int hungarian( vector<vector<int>> A ){
    const int INF = 1e18;
    int n = A.size();
    int m = A.empty() ? 0 : A[0].size();
    vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for ( int i = 1; i <= n; ++i ) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv( m + 1, INF );
        vector<bool> used( m + 1, false );
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;
            for ( int j = 1; j <= m; ++j )
                if ( !used[j] ) {
                    int cur = A[i0-1][j-1] - u[i0] - v[j];
                    if ( cur < minv[j] )
                        minv[j] = cur, way[j] = j0;
                    if ( minv[j] < delta )
                        delta = minv[j], j1 = j;
                }
            for ( int j = 0; j <= m; ++j )
                if ( used[j] )
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while ( p[j0] != 0 );
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    assignment = p;
    return -v[0];
}

void AmeSameDoko(){

    int n, k; cin >> n >> k;
    int a[n], b[n]; 
    for ( int i = 0; i < n; i++ ) cin >> a[i] >> b[i];

    vector<vector<int>> A(n,vector<int>(n,0));

    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if ( j < k ) A[i][j] = -(a[i]+j*b[i]);
            else A[i][j] = -((k-1)*b[i]);
        }
    }
    
    int x = -hungarian(A);

    cout << x << endl;

    vector<int> ans;
    for ( int i = 1; i < k; i++ ) ans.push_back(assignment[i]);
    for ( int i = k+1; i <= n; i++ ){
        ans.push_back(assignment[i]);
        ans.push_back(-assignment[i]);
    } 
    ans.push_back(assignment[k]);

    cout << ans.size() << endl;
    for ( auto c : ans ) cout << c << ' '; cout << endl;
    
}
 
signed main(){
    Wah();
    int tt = 1;
    cin >> tt;
    while ( tt-- > 0 ){
        AmeSameDoko();
    }      
    return 0;
}