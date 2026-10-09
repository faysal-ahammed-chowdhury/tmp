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
template <typename T> T mysqrt( T x ){ T ans = 0;for (T k = 1 << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
// Operator overloads
template<typename T1, typename T2> /*cin >> pair<T1, T2>*/ istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> /* // cin >> vector<T> */istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> /* // cout << pair<T1, T2> */ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> /* // cout << vector<T> */ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}

// priority_queue <int, vector<int>, greater<int>> q;


const int maxn = 2e5 + 14, mod = 1e9 + 7;
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
ll nCr(ll n, ll m){   ll s = 1;for (ll i = n - m + 1; i <= n; i++) {s = s * i / (i - n + m);  }return s;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}


vll g[maxn];
int n,m;

int shortest_cycle(){
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, (int)(1e9));
        vector<int> par(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int child : g[x]) {
                if (dist[child] == (int)(1e9)) {
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                }
                else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}

void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];


    fr ( i, maxn )
        g[i].clear();

    
    cin >> n >> m;
    fr ( i, m ){
        int x,y;    cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }


    int ans = shortest_cycle();

    if ( ans == -1 ){
        cout << "impossible\n";
    } else {
        cout << ans << endl;
    }




}

    
signed main(){
    // class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    fast(); 
    ll tt = 1;
    cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ": ";
        solve();
    }      
    return 0;
}    