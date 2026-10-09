#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
const int lim = 5+5;
int dp[lim+10][lim+10];

int main(){

    for ( int i = 0; i < lim; i++ )   dp[lim][0] = dp[i][i] = 1;
    for ( int i = 0; i <= lim; i++ ){
        for ( int j = 1; j < i; j++ ){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= mod; 
        }
        for ( int j = i+1; j <= lim; j++ ) 
            dp[i][j] = -1;
    }

    for ( int i = 0; i < lim; i++ ){
        for ( int k = 0; k < lim-i; k++ ) cout << ' ';
        for ( int j = 0; j < i; j++ ){
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
}