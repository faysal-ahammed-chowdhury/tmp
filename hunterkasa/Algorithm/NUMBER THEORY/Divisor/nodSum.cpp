#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <valarray>
#include <set>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, a, n )  for( long long i = a; i <= n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define pb              push_back
#define vll             vector<ll>
#define ss              second
#define ff              first
#define ub(v,x)             upper_bound(all(v),x)-v.begin();
#define ul(v,x)             upper_bound(all(v),x)-v.begin();

typedef long long int lli;
typedef long long ll;
typedef unsigned long long ull;

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}

ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll nCr(ll n, ll m){   ll s = 1;for (ll i = n - m + 1; i <= n; i++) {s = s * i / (i - n + m);  }return s;}
ll powmod(ll a, ll b, ll p){a%=p;if(a==0)return 0;if (b==0) return 1;ll product = 1;while (b>0){if ( b & 1 ){   /* // b % 2 == 1 */product *= a;product %= p;b--;}a*=a;a%=p;b/=2;/* // b >> 1 */}return product;}
ll inv(ll a, ll p){return powmod(a, p-2, p);}
const int N = 1000003;
// ll fact[1000003];
// ll nCk(ll n, ll k, ll p){return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;}

const int nMax = 1e8;
bitset<nMax> bit;
void seive(){
    bit.set();
    bit[0] = bit[1] = 0;
    for ( int i = 2; i * i <= nMax; i++ ){
        if (bit[i]) {
			for (int j = i * i; j <= nMax; j += i) bit[j] = 0;
		}
    }
}

// nodSum = number of divisor sum 
// 6/8/22 dd/mm/yy

// precomp all the divisors using seive technique 
const int Nnod=1e6+10;
ll nod[Nnod];
void preComp(){
    for ( int d = 1; d <= Nnod; d++ ){
        for ( int i = d; i <= Nnod; i += d ){
            nod[i]++;
        }
    }
}

// calculate the prefix of the array
ll pre[Nnod];
void prefix(){
    for ( int i = 1; i <= Nnod; i++ )
        pre[i] = pre[i-1] + nod[i];
}

void solve(){
    
    ll L,R; cin >> L >> R;

    cout << pre[R]-pre[L] << endl;
    

}

    
    
signed main(){
    fast();
    preComp();
    prefix();
    ll tt = 1;
    // cin >> tt;    
    // ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";    
        solve();
    }      
} 