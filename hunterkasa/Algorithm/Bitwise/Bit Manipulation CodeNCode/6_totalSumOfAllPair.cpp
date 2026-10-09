#include <iostream>
using namespace std;


int main(){
    
        int arr[1001];
        int n, res = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        
        for ( int i = 0; i < 31; i++ ){
            int cntz = 0, cnto = 0;
            
            for ( int j = 1; j <= n ; j++ ){
                if ( arr[j] & ( 1 << i ) )
                    cnto++;
                else cntz++;
            }
            int p = cntz * cnto;
            
            res += ( 1 << i ) * p;
        }
        cout << res << endl;

}