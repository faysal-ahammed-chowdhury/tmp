// https://vjudge.net/problem/UVA-459?fbclid=IwAR2OCNVsjZ7US7KuyssB8SHM0rnVDSFbdFay22BVCxKNpRX3A1C4E2C2Imc
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
        freopen("input.txt","r",stdin);
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

ll extendedGCD(ll a, ll b, ll& x, ll& y) {
    if (0 == b) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll res = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return res;
}


int dx[] = {0,0,1,-1, 1,1, -1,-1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

int cnt = 0;
int vis[1000005];
vector<int> graph[1000005];

void dfs(int node){
    vis[node] = 1;
    for ( int i = 0; i < graph[node].size(); i++ ){
        int x = graph[node][i];
        if ( !vis[x] ){
            dfs(x);
        }
    }
}


void solve(){
    
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i]; 
    
    string s;
    char c; cin >> c;
    ll n = c-'A'+1;
    cin.ignore();

    while( getline(cin,s) && s != "" ){
    
        graph[s[0]-'A'].push_back(s[1]-'A');
        graph[s[1]-'A'].push_back(s[0]-'A');
        
    }
    
    for ( int i = 0; i < n; i++ ){
        if ( vis[i] == 0 ){
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;
    cnt = 0;
}

    
    
signed main(){
    fast();
    ll tt = 1;
    cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        cnt = 0;
        // cout << "Case " << i++ << ": ";    
        solve();
        memset(vis,0,sizeof(vis));
        memset(graph,0,sizeof(graph));
        if (tt)
            cout << endl;
    }      
} 