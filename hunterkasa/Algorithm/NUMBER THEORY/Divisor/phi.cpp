ll phi(ll n) {
    ll result = n;
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
// sqrt(n)


const int N = 1e5+10;
vector<int> phi(N + 1);
void phi_1_to_n() {
    for ( int i = 0; i <= N; i++ ) phi[i] = i;
    for ( int i = 2; i <= N; i++ ) {
        if ( phi[i] == i ) {
            for ( int j = i; j <= N; j += i )
                phi[j] -= phi[j] / i;
        }
    }
}