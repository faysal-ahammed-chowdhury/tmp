#include <iostream>
using namespace std;

#define lli long long int

int main(){
    
    lli t, n;
    cin >> t;
    
    while ( t-- ){
        cin >> n;
        lli ar[n+1];
        for ( int i = 1; i < n; i++ ){
            cin >> ar[i];
        }
        lli cnt, res = 0; 
        for ( lli i = 1; i <= n; i++ ){
            cnt = i*(n-i+1);
            if ( cnt % 2 ) res ^= ar[i];
        }
        cout << res << endl;
    }
    
    
}