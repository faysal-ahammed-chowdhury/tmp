#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugArr(arr, n)
#endif

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define int long long






void AmeDoko(){

    int n; cin >> n;
    vector a(n+10,vector(n+10, vector(n+10,0)));
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            for ( int k = 0; k < n; k++ ){
                cin >> a[i][j][k];
            }
        }
    }

    // to make it a n-d prefix sum increase innerloop and increase mask and bit values
    
    vector pre(n+10,vector(n+10, vector(n+10,0)));
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            for ( int k = 0; k < n; k++ ){
                // pre[i+1][j+1][k+1] = pre[i][j][k] + a[i][j][k] + pre[i+1][j+1][k] + pre[i+1][j][k+1] + pre[i][j+1][k+1];
                // pre[i+1][j+1][k+1] -= (pre[i+1][j][k] + pre[i][j][k+1] + pre[i][j+1][k]);
                
                
                ll sum = a[i][j][k];

                for ( int mask = 0; mask < 8; mask++ ){

                    vector<int> id;
                    for ( int bit = 0; bit < 3; bit++ ){
                        if ( (mask & (1<<bit)) ){
                            if ( bit == 0 ) id.push_back(i+1);
                            if ( bit == 1 ) id.push_back(j+1);
                            if ( bit == 2 ) id.push_back(k+1);
                        } else {
                            if ( bit == 0 ) id.push_back(i);
                            if ( bit == 1 ) id.push_back(j);
                            if ( bit == 2 ) id.push_back(k);
                        }
                    }

                    if ( __builtin_popcount(mask) % 2 != 1 ){
                        sum += pre[id[0]][id[1]][id[2]];
                    } else {
                        sum -= pre[id[0]][id[1]][id[2]];
                    }

                }

                pre[i+1][j+1][k+1] = sum;

            }
        }
    }

    int q; cin >> q;
    while ( q-- > 0 ){
        int lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;

        ll ans = 0;
        for ( int i = 0; i < 8; i++ ){
            
            vector<int> id;
            for ( int j = 0; j < 3; j++ ){
                if ( (i&(1<<j)) ){
                    if ( j == 0 ) id.push_back(lx-1);
                    if ( j == 1 ) id.push_back(ly-1);
                    if ( j == 2 ) id.push_back(lz-1);
                } else {
                    if ( j == 0 ) id.push_back(rx);
                    if ( j == 1 ) id.push_back(ry);
                    if ( j == 2 ) id.push_back(rz);
                }
            }

            if ( __builtin_popcount(i) % 2 != 0 ){
                ans -= pre[id[0]][id[1]][id[2]];
            } else {
                ans += pre[id[0]][id[1]][id[2]];
            }
        }

        cout << ans << endl;
        
    }

}   

signed main(){
    fast();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        AmeDoko();
    }      
    return 0;
}        