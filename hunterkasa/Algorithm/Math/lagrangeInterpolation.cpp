// works for k <= 1e6 and x <= 1e12 
// finds  1^k + 2^k + ..... + x^k
const int mod = 1e9+7;
ll binpow( ll a, ll b ){
    ll res = 1;
    while ( b ){
        if ( b & 1 )    res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll modinv( ll a ){
    return binpow(a,mod-2);
}
int interpolate( ll x, ll k, bool bf = false ){
    if ( k == 0 )   return x;
    // find 1^k + 2^k + ..... + x^k
    // (k+1) degree polynomial -> (k+2) points
    if ( x <= k+1 || bf ){
        int s = 0;
        for ( int i = 1; i <= x; i++ ){
            s = (s + binpow(i,k) ) % mod;
        }
        return s;
    }
    vector<ll> pre(k+2), suf(k+2), inv(k+2);
    inv[0] = 1;
    pre[0] = x;
    suf[k+1] = x - (k+1);
    for ( int i = 1; i <= k; i++ )  pre[i] = pre[i-1] * (x-i) % mod; // numerator prefix product
    for ( int i = k; i >= 1; i-- ) suf[i] = suf[i+1] * (x-i) % mod; // denominator suffix product
    for ( int i = 1; i <= k+1; i++ ) inv[i] = inv[i-1] * modinv(i) % mod; // denominator factorial

    ll ans = 0;
    ll yi = 0; // 0^k + .. + i^k
    ll num, denom;

    for ( int i = 0; i <= k+1; i++ ){
        yi = (yi+binpow(i,k))%mod; // interpolate point: (i,yi)

        if ( i == 0 )   num = suf[1];
        else if ( i == k+1 )    num = pre[k];
        else num = pre[i-1]*suf[i+1] % mod;

        denom = inv[i] * inv[k+1-i] % mod;

        if ( (i + k) & 1 ) ans += (yi*num%mod) * denom % mod; // (-1)^(i-deg) however deg is k+1 here
        else ans -= (yi*num % mod) * denom % mod;
        
        ans = (ans % mod + mod) % mod;
    }
    return ans;
} 