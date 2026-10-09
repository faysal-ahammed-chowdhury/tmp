#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debuga(a, n)
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




struct point {
    int x, y;
    point(){}
    point( int x, int y ){ this->x = x; this->y = y; }
    bool operator<( const point &other ){
        if ( x == other.x ) return y < other.y;
        return x < other.x;
    }
    bool operator==( const point &other ){
        return ( x == other.x && y == other.y );
    }
    bool operator!=( const point &other ){
        return ( x != other.x || y != other.y );
    }
    point operator-( const point &other ){
        return {x-other.x, y-other.y};
    }
};

ld crossProduct( point &a, point &b, point &c ){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

vector<point> hull( vector<point> &a ){
 
	vector<point> v = a;
    sort(v.begin(), v.end());
 
    vector<point> lower, upper;
 
    for ( auto& p : v ) {
        while ( lower.size() >= 2 && crossProduct(lower[lower.size()-2], lower.back(), p) <= 0 )
            lower.pop_back();
        lower.push_back(p);
    }
 
    for ( int i = v.size()-1; i >= 0; i-- ) {
        point p = v[i];
        while ( upper.size() >= 2 && crossProduct(upper[upper.size()-2], upper.back(), p) <= 0 )
            upper.pop_back();
        upper.push_back(p);
    }
 
    lower.pop_back();
    upper.pop_back();
 
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;

}

ld pointSegmentDistance( const point &A, const point &B, const point &P ) {
    ld dx = B.x - A.x;
    ld dy = B.y - A.y;

    if ( dx == 0 && dy == 0 ) 
        return sqrt((P.x - A.x)*(P.x - A.x) + (P.y - A.y)*(P.y - A.y));

    // projection t of P onto AB in [0,1]
    ld t = ((P.x - A.x)*dx + (P.y - A.y)*dy) / (dx*dx + dy*dy);

    if ( t < 0 ) t = 0;
    else if ( t > 1 ) t = 1;

    ld projX = A.x + t*dx;
    ld projY = A.y + t*dy;

    return sqrt((P.x - projX)*(P.x - projX) + (P.y - projY)*(P.y - projY));
}


void senritsu() {   

    int n; cin >> n;
    vector<point> a(n); for ( int i = 0; i < n; i++ ) cin >> a[i].x >> a[i].y;

    a = hull(a);
    n = a.size();
    
    cout << n << endl;
    for ( auto c : a ) cout << c.x << ' ' << c.y << endl;

}

signed main() {
    Wah();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}