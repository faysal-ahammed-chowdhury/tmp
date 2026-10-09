 
int totalDigits(int n){
    if ( n <= 0 ) return 0;
    int p = 1;
    int total = 0;
    for ( int d = 1; d <= 18; d++ ) {
        int L = p;
        int R = min(n, p * 10 - 1);
        if ( R >= L ) total += (R - L + 1) * 1LL * d;
        p *= 10;
        if ( p > n ) break;
    }
    return total;
}
 
int sumOfDigits( int n ) {
    if ( n <= 0 ) return 0;
    int res = 0;
    for ( int p = 1; p <= n; p *= 10 ) {
        int pp10 = p * 10;
        int high = n / pp10;
        int cur  = (n / p) % 10;
        int low  = n % p;
        res += high * p * 45 + (cur * (cur - 1) / 2) * p + cur * (low + 1);
    }
    return res;
}