// https://www.youtube.com/watch?v=d3plbvfZbdw&list=PL5DyztRVgtRUVORP3AXvX91uovcaZv0q9&index=12&ab_channel=CodeNCode
#include <bits/stdc++.h>
using namespace std;


#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define vll             vector<long long>

typedef long long ll;


void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    
    ll n;   cin >> n;
    vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    ll ans = 0;
    fr ( i, 31 ){
        int z = 0, o = 0;
        fr ( j, n ){
            if ( a[j] & ( 1 << i ) )
                o++;
            else 
                z++;
        }
        int p = o*z;
        ans += (1<<i)*p;
    } 

    cout << ans << endl;
    

}
    
    
int main(){
    ll tt = 1;
    // cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
}   