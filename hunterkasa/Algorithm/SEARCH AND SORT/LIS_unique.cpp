#include <bits/stdc++.h>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define fr1( i, a, n )  for( long long i = a; i < n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n-1; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define pb              push_back
#define vll             vector<long long>
#define mll             map<long long,long long>
#define vpll            vector<pair<long long,long long>>
#define lb(v,x)         lower_bound(all(v),x)-v.begin()
#define ub(v,x)         upper_bound(all(v),x)-v.begin()
#define precision(a)    cout << fixed << setprecision(a) 
#define mem(x,y)        memset(x,y,sizeof(x))
#define pll             pair<ll,ll>
#define sr(a)           sort(all(a))
#define srg(a)          sort(all(a),greater<>())
#define re              return;
#define acc(a)          accumulate(all(a),0LL)

#define int long long
typedef long long ll;

template <typename T> T myfloor( T a, T b ){ return a/b; } // careful for negetive numbers
template <typename T> T myceil( T a, T b ){ return (a+b-1)/b; }
template <typename T> T mysqrt( T x ){ ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}

// priority_queue <int, vector<int>, greater<int>> q;


int largest( vll &a, int n ){
    unordered_map<int,int> id;
    int ans = 0;
    for ( int i = 0, j = 0; i < n; i++ ){
        j = max(id[a[i]], j);
        ans = max(ans,i-j+1);
        id[a[i]] = i+1;
    }
    return ans;
}

void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    
    ll n;   cin >> n;
    vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    cout << largest(a,n) << endl;
    
}

    
signed main(){
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    fast(); 
    ll tt = 1;
    // cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
    return 0;
}   