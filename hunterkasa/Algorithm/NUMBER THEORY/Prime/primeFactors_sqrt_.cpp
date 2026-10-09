#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;  cin >> n;
    ll cnt = 0;
    
    for ( ll i = 1; i * i <= n; i++ ){
        if ( n % i == 0 ){
            cnt++; // i is a factor
            
            if ( i != n/i )
                cnt++;  // ( n / i ) is also a factor
        } 
    }
    cout << cnt-1;
}