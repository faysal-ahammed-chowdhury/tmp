#include <bits/stdc++.h>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            '\n'

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
typedef long double ld;
#define int long long






const ll p = 1e9+7;
ll exp(ll x, ll n, ll m) {
	x %= m; 
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void tohka(){
    // burnside lemma 
    // (1/n) * summation of all phi(i) * k^(n/i) where i is the divisor of n
    int n, k;   cin >> n >> k;
    ll ans = 0;
    for ( int i = 1; i <= n; i++ ){
        if ( (n % i) ) continue;
        ans = (ans + (phi(i)%p*exp(k,n/i,p)%p) % p) % p;
    }
    cout << (ans*exp(n,p-2,p)) % p << endl;
}   

signed main(){
    fast();
    int tt = 1;
    // cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        tohka();
    }      
    return 0;
}        