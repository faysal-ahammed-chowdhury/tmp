// #pragma comment(linker, "/STACK:268435456");
        // "cpp": "cd $dir && g++ -std=c++17 -O2 '-Wl,--stack,1073741824' $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set os<int> os;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// o_set<int> ms;
// ms.erase(ms.find_by_order(ms.order_of_key(2)));
// order_of_key(x) strictly less than x 
// find_by_order(k) kth smallest element in k


template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}


// priority_queue <int, vector<int>, greater<int>> q;
// string w = string(n, '1');
// vector<vector<int>> a(n, vector<int>(m));

int idx[n];
itoa(idx,idx+n,0);
sort( idx,idx+n,[&](int i, int j){ return a[i] < a[j]; } );

// bitwise accumulation
int ans = accumulate(a,a+n,a[0],bit_and<int>());

// declare custom comparator with data structure
bool cmp( pair<int,int> &a, pair<int,int> &b ){
    if ( a.first == b.first )
        return a.second > b.second;
    return a.first < b.first;
}
priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(&cmp)> pq(cmp);

const int nMax = 1e8;
bitset<nMax> bit;
vector<int> primes;
void seive(){
    bit.set();bit[0] = bit[1] = 0;
    for ( int i = 2; i * i <= nMax; i++ ){
        if (bit[i]) {
            for (int j = i * i; j <= nMax; j += i ) bit[j] = 0;
        } 
    }
    for ( int i = 0; i < nMax; i++ ) 
        if ( bit[i] )
            primes.push_back(i);
}
void segSeive(ll l, ll r){bool isPrime[r-l+1];for ( int i = 0; i < r-l+1; i++ )isPrime[i] = true;if ( l == 1 ) isPrime[0] = false;for ( int i = 0; primes[i]*primes[i] <= r; i++ ){int currentPrime = primes[i];ll base = (l/currentPrime)*currentPrime;if ( base < l )base += currentPrime;for ( ll j = base; j <= r; j+= currentPrime ){isPrime[j-l] = false;}if ( base == currentPrime ) isPrime[base-l] = true;} /* for ( int i = 0; i < r - l + 1; i++ )if ( isPrime[i] )cout << i+l << endl; */}

const int MAX = 1e5+100; 
bool v[MAX];
int spf[MAX];
void sp(){
	for (int i = 2; i < MAX; i += 2)	spf[i] = 2;
	for (int i = 3; i < MAX; i += 2){
		if (!v[i]){
			spf[i] = i;
			for (int j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, spf[j*i] = i;
			}
		}
	}
}

// class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
int myrand(int mod) {
    return mt()%mod;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
T rand(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}

mt19937 rnd(time(NULL));

uint64_t xor_hash(int a, int b) {
    uint64_t hash = 0x9E3779B97F4A7C15ULL;
    hash ^= (uint64_t)a + 0x517cc1b727220a95ULL; 
    hash ^= (uint64_t)b * 0x6c8e9cf570932bd5ULL;
    hash *= 0x100000001B3ULL;
    return hash;
}

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
const int N = 2e6+100;
int fact[N];
const int mod = 998244353;
void pre(){
    fact[0] = 1;
    for ( int i = 1; i < N; i++ ){
        fact[i] = (fact[i-1] * i) % mod;
    }
}
int chooose( int n, int r ){
    if ( n < r ) return 0;
    return fact[n] * ModInv(fact[r] * fact[n - r] % mod, mod) % mod;
}


///////////////////////////////////////////////////////////////////
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
const int mod = 998244353;
const int N = 1e6+100; 
int fact[N], ifact[N];
void pre(){
    fact[0] = 1;
    ifact[0] = 1;
    for ( int i = 1; i < N; i++ ){
        fact[i] = (fact[i-1] * i) % mod;
    }
    ifact[N-1] = ModInv(fact[N-1], mod);
    for ( int i = N - 2; i >= 1; i-- ){
        ifact[i] = (ifact[i+1] * (i + 1)) % mod;
    }
}
int chooose( int n, int r ){
    if ( n < r || r < 0 ) return 0;
    return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
/////////////////////////////////////////////////////////////////////

const int MOD = 998244353;
inline int add( int x, int y ) { return ( ( x + y ) % MOD + MOD) % MOD; }
inline int mul( int x, int y ){ return x * 1ll * y % MOD; }
inline int binpow( int x, int y ) { int z = 1; while( y ){ if( y % 2 == 1 ) z = mul( z, x );x = mul( x, x ); y /= 2; } return z; }
inline int inv( int x ){ return binpow( x, MOD - 2 ); }
inline int divide( int x, int y ){ return mul( x, inv( y ) ); }






int computeXOR(int n) {
    if ( n % 4 == 0 ) return n;
    if ( n % 4 == 1 ) return 1;
    if ( n % 4 == 2 ) return n + 1;
    if ( n % 4 == 3 ) return 0;
}




#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

///unordered_map anti hash      //unordered_map anti hash      //unordered_map anti hash      //unordered_map anti hash

struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t>x) const { 
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
        return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1); 
    } 
    size_t operator()(const string& str) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash = FIXED_RANDOM;
        for(char c:str) {hash^=c+0x9e3779b9+(hash<<6)+(hash>>2);}
        return splitmix64(hash);
    }
    size_t operator()(const pair<uint64_t, pair<uint64_t,uint64_t>>& x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = splitmix64(x.first + FIXED_RANDOM);
        uint64_t h2 = splitmix64(x.second.first + FIXED_RANDOM);
        uint64_t h3 = splitmix64(x.second.second + FIXED_RANDOM);
        return h1 ^ (h2 >> 1) ^ (h3 << 1);
    }
};
//gp_hash_table<int, int,custom_hash>mp;
//gp_hash_table<pair<int,int>, int,custom_hash>mp;



string add( string &num1, string &num2 ) {
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    while ( i >= 0 || j >= 0 || carry ) {
        int sum = carry;
        if ( i >= 0 ) sum += num1[i--] - '0'; 
        if ( j >= 0 ) sum += num2[j--] - '0';
        carry = sum / 10;
        result += ( sum % 10 ) + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}


// accumulate(a,a+n,0ll,bit_xor());