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
 







class  Mint  // MODULAR INTEGERS IN MONTGOMERY FORM
{
  private:
    using  u64  = uint64_t;
    using  u128 = __uint128_t;

    // CLASS MEMBER DATA
    static u64  mod;
    static u64  N;      //  mod * N ≡ -1 MOD 2^64
    static u64  R;      //  2^128 MOD mod
    u64         a;

  public:
    Mint() = default;
    Mint( int64_t  b ) : a( reduce( u128( b ) * R ) )  {};

    // GETS AND SETS
    static u64  get_mod()  { return  mod; }
    u64  get() const  {
        u64  ret = reduce( a );
        return  ret >= mod ? ret - mod : ret;
    }
    static void  set_mod( u64 m )  {
        N = mod = m;
        for( int i=0 ; i<5 ; ++i )   N *= 2 - m * N;
        N = -N;
        R = -u128( m ) % m;
    }	    

    // OPERATORS
    Mint &operator += ( const Mint &b )  {
        if( int64_t( a += b.a - 2 * mod ) < 0 )   a += 2 * mod;
        return  *this;
    }
    Mint &operator -= ( const Mint &b )  {
        if( int64_t( a -= b.a ) < 0 )   a += 2 * mod;
        return  *this;
    }
    Mint &operator *= ( const Mint &b )  {
        a = reduce( u128( a ) * b.a );
        return  *this;
    }

    Mint operator  + (const Mint &b) const { return Mint(*this) += b; }
    Mint operator  - (const Mint &b) const { return Mint(*this) -= b; }
    Mint operator  * (const Mint &b) const { return Mint(*this) *= b; }
    Mint operator    - () const {  return  Mint() - Mint(*this); }
    Mint& operator  ++ ()  { return  *this += Mint( 1 ); }
    Mint& operator  -- ()  { return  *this -= Mint( 1 ); }

    bool operator == ( const Mint &b ) const  {
        return ( a >= mod ? a - mod : a ) == ( b.a >= mod ? b.a - mod : b.a );
    }
    bool operator != ( const Mint &b ) const  {
        return ( a >= mod ? a - mod : a ) != ( b.a >= mod ? b.a - mod : b.a );
    }

    // METHODS  
    Mint  pow( u64  n ) const  {
        Mint  ret( 1 ),  mul( *this );
        while( n > 0 )  { if( n & 1 )  ret *= mul;   mul *= mul;  n >>= 1; }
        return  ret;
    }

    friend ostream &operator << ( ostream &os, const Mint &b )  {
        return  os << b.get();
    }
    friend istream &operator >> ( istream &is, Mint &b )  {
        int64_t  t;  is >> t;
        b = Mint( t );
        return  is;
    }

  private:
    static u64 reduce( const u128 &b )  {
        return ( b + u128( u64( b ) * u64( N ) ) * mod ) >> 64; 
    }
};

typename  Mint::u64   Mint::mod,  Mint::N,  Mint::R;


// ===================  BEGIN MILLER RABIN  ===================
static inline bool  isPrime( const uint64_t n )
{
    static constexpr uint64_t  primeMask = 2891462833508853932ULL;
    if( n < 64 )  { return  primeMask >> n & 1; }  // BITMASK SMALL PRIMES
    if( !( n & 1 ) )   return  false;

    Mint::set_mod( n );

    uint64_t  u = n - 1;    
    int  s,  t = 0;
    while( !( u & 1 ) )  ++t,  u >>= 1;

    // FROM  http://miller-rabin.appspot.com/    SEE REMARKS
    vector<uint64_t>  seeds;
    if( n < 1050535501ULL )               seeds = { 336781006125ULL, 9639812373923155ULL };
    else if( n < 350269456337ULL )        seeds = { 4230279247111683200ULL, 14694767155120705706ULL,
                              16641139526367750375ULL };
    else if( n < 55245642489451ULL )      seeds = { 2ULL, 141889084524735ULL, 1199124725622454117ULL,
                              11096072698276303650ULL };
    else if( n < 7999252175582851ULL )    seeds = { 2ULL, 4130806001517ULL, 149795463772692060ULL, 
                              186635894390467037ULL, 3967304179347715805ULL };
    else if( n < 585226005592931977ULL )  seeds = { 2ULL, 123635709730000ULL, 9233062284813009ULL,
                              43835965440333360ULL, 761179012939631437ULL, 1263739024124850375ULL };
    else  seeds = { 2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL };

    for( const auto &a : seeds )  { 
        uint64_t  p = a < n ? a : a % n;
        if( p == 0 )   continue;
        
        Mint  x = Mint( p ).pow( u );

        if( x != 1 )  {
            for( s=0 ; s<t && x!=n-1 ; ++s ) 
                if( (x *= x) == 1 )   return  false;
            if( t == s )   return  false;
        }
    }
    return  true;
}
  


vector<int> a;
bool dp[20];
int vis[20];
int sz = 0;
int val = 1;


int rec( int pos ){

    if ( pos == a.size() ) return 1;

    if ( a[pos] == 0 ) return 0;

    if ( vis[pos] == val ) return dp[pos];
    vis[pos] = val;
    
    int ret = 0, num = 0;
    int upto = a.size();
    if (pos == 0) upto--;

    for (int i = pos; i < upto; i++) {
        num = num * 10 + a[i];
        if (isPrime(num) == 1) ret |= rec(i + 1);
    }
    return dp[pos] = ret;
    
}

void AmeDoko(){

    int n; cin >> n;
    n += (n%2 == 0);
    while ( 1 ){
        a.clear();
        int x = n;
        while ( x > 0 ){
            a.push_back(x % 10);
            x /= 10;
        }
        reverse(a.begin(), a.end());
        val++;

        
        if ( isPrime(n) && rec(0)) {
            cout << n << endl;
            return;
        }
        n += 2;
    }
    
}   
 
signed main(){
    Wah();
    int tt = 1;
    cin >> tt;
    while ( tt-- > 0 ){
        AmeDoko();
    }      
    return 0;
}         