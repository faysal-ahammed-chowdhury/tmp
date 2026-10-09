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


struct circle {
    ld cx, cy, r;
    circle(ld x=0, ld y=0, ld radius=0) : cx(x), cy(y), r(radius) {}
};
circle circumcircle(const point &A, const point &B, const point &C) {
    ld x1 = A.x, y1 = A.y;
    ld x2 = B.x, y2 = B.y;
    ld x3 = C.x, y3 = C.y;
    ld D = 2 * (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    if (D == 0) {
        // Collinear points, no circle
        return circle(0,0,-1);
    }
    ld Ux = ((x1*x1 + y1*y1)*(y2 - y3) + (x2*x2 + y2*y2)*(y3 - y1) + (x3*x3 + y3*y3)*(y1 - y2)) / D;
    ld Uy = ((x1*x1 + y1*y1)*(x3 - x2) + (x2*x2 + y2*y2)*(x1 - x3) + (x3*x3 + y3*y3)*(x2 - x1)) / D;
    ld R = sqrt((Ux - x1)*(Ux - x1) + (Uy - y1)*(Uy - y1));
    return circle(Ux, Uy, R);
}
// point A(0,0), B(1,0), C(0,1);
// circle cir = circumcircle(A, B, C);
// if(cir.r < 0) cout << "Points are collinear, no circle\n";
// else cout << "Center: (" << cir.cx << "," << cir.cy << "), Radius: " << cir.r << endl;
