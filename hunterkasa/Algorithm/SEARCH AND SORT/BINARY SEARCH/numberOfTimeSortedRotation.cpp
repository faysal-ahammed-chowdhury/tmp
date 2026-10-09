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




void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    int n;  cin >> n;
    vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    int res = -1;
    int low = 0, high = n - 1;
    if (a[low] < a[high]){
        cout << 0 << endl; re
    }
        
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (a[mid] <= a[prev] && a[mid] <= a[next]){
            res = mid;
            break;
        }
        else if (a[mid] <= a[high])
            high = mid - 1;
        else if (a[mid] >= a[0])
            low = mid + 1;
    }

    cout << res << endl;


}

    
signed main(){
    // class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    fast(); 
    ll tt = 1;
    // cin >> tt;
    // ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
    return 0;
}    
