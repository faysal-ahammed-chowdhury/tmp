#include <iostream>
using namespace std;

int main(){
    int t;   cin >> t;
    while ( t-- ){
        int n;  cin >> n;
        int arr[n+1];
        
        for ( int i = 1; i <= n; i++ ){
            cin >> arr[i];
        }
        int res = 0;
        
        for ( int i = 1; i <= n; i++ ){
            res = res ^ arr[i];
        }
        for ( int i = 1; i <= n; i++ ){
            res = res ^ i;
        }
        
        int setBit = res & ~(res-1);
        
        int l = 0, r = 0; 
        
        for ( int i = 1; i <= n; i++ ){
            if ( arr[i] & setBit ){
                l = l ^ arr[i];
            } else {
                r = r ^ arr[i];
            }
        }
        
        for ( int i = 1; i <= n; i++ ){
            if ( i & setBit ){
                l = l ^ i;
            } else {
                r = r ^ i;
            }
        }
        
        bool isLmissing = true;
        for ( int i = 1; i <= arr[i]; i++ ){
            if ( arr[i] == l ){
                isLmissing = false;
                break;
            }
        }
        
        if ( isLmissing == true )   cout << l << " " << r  <<  endl;
        else cout << r << " " << l << endl;
    }
}