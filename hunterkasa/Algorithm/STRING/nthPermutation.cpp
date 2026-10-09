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
// #define int long long
 








long long fact[30];
void pre(){
    fact[0] = 1;
    for ( int i = 1; i <= 22; i++ ) fact[i] = (ll)(fact[i-1]*i);
}

string s; 
int n;
int freq[26];

void rec( int pos, long long k ){
    
    if ( pos == n ) return;

    int i;
    for ( i = 0; i < 26; i++ ){
        if ( !freq[i] ) continue;

        freq[i]--;
        
        ll cnt = accumulate(freq,freq+26,0ll);
        ll res = fact[cnt];

        for ( int j = 0; j < 26; j++ )
                res /= fact[freq[j]];
        
        if ( res < k ){
            k -= res;
            freq[i]++;
        } else {
            break;
        }
        
    }

    cout << char('a'+i);
    rec(pos+1, k);
}

void AmeDoko(){

    memset(freq,0,sizeof freq);

    long long a, b, k; cin >> a >> b >> k;
    n = a + b;
    for ( int i = 0; i < a; i++ ) s += 'a';
    for ( int i = 0; i < b; i++ ) s += 'b';

    for ( auto c : s ) freq[c-'a']++;

    ll all = fact[n];
    for ( int i = 0; i < 26; i++ ) all /= fact[freq[i]];

    rec( 0, k );
    cout << endl;

}   
 
signed main(){
    pre();
    Wah();
    int tt = 1;
    // cin >> tt;
    // int i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        AmeDoko();
    }      
    return 0;
}         