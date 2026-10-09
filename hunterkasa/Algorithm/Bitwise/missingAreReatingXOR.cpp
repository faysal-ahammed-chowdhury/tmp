// https://www.youtube.com/watch?v=V5vce2fxvkg&list=PL5DyztRVgtRUVORP3AXvX91uovcaZv0q9&index=14&ab_channel=CodeNCode
#include <bits/stdc++.h>
using namespace std;


#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define vll             vector<long long>

typedef long long ll;


void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    
    ll n;   cin >> n;
    vll a(n+1);   for ( int i = 1; i <= n; i++ )  cin >> a[i];

    int ans = 0;
    for ( int i = 1; i <= n; i++ ) ans ^= a[i];
    for ( int i = 1; i <= n; i++ ) ans ^= i;

    int setbit = ans & ~(ans-1);

    int l = 0, r = 0;

    for ( int i = 1; i <= n; i++ ){
        if ( a[i] & setbit ){
            l ^= a[i];
        } else {
            r ^= a[i];
        }
    }

    for ( int i = 1; i <= n; i++ ){
        if ( i & setbit ){
            l ^= i;
        } else {
            r ^= i;
        } 
    }
    
    bool isMissing = true;
    fr ( i, n ){
        if ( a[i] == l ){
            isMissing = false;
            break;
        }
    }

    if ( isMissing ){
        cout << "missing: " << l << endl << "repeating: " << r << endl;
    } else {
        cout << "missing: " << r << endl << "repeating: " << l << endl;
    }
    

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