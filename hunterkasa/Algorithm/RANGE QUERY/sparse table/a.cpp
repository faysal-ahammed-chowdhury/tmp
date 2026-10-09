// https://codeforces.com/problemset/problem/2050/F
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugA(a, n)
#endif

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'

void Wah() {
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt","w",stdout);
    #endif
}

typedef vector<long long> vll;
typedef long double ld;
#define int long long
#define ll long long


int const nmax = 200000;
int const lgmax = 20; 
int v[nmax];
int rmq[lgmax + 1][nmax]; 
int lg( int number ) {
    if ( number == 0 ) return -1;
    return 31 - __builtin_clz(number);
}

void precompute( int n ) {
    for( int i = 0; i < n; i++ ) {
        rmq[0][i] = v[i];
    }
    for(int h = 1; h <= lgmax; h++) {
        for(int i = 0; i + (1 << h) <= n; i++) {
            rmq[h][i] = gcd(rmq[h - 1][i], rmq[h - 1][i + (1 << (h - 1))]);
        }
    }
}

int extract(int L, int R) {
    int len = R - L + 1;
    int h = lg(len);
    return gcd(rmq[h][L], rmq[h][R - (1 << h) + 1]);
}

void senritsu() {   

    int n, q; cin >> n >> q;
    int a[n+1]{}; for ( int i = 1; i <= n; i++ ) cin >> a[i];

    for ( int i = 2; i <= n; i++ ){
        v[i-1] = abs(a[i] - a[i-1]);
    }
    precompute(n+1);

    while ( q-- > 0 ){
        int l, r; cin >> l >> r;
        if ( l == r ){
            cout << 0 << ' ';
            continue;
        }
        r -= 1;
        cout << extract(l,r) << ' ';
    }
    cout << endl;

}

signed main() {
    Wah();
    int tt = 1;
    cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}