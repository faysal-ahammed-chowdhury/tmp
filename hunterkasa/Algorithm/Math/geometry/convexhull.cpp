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



struct point{
    int x, y;
    bool operator<(point &other){
        if ( x == other.x ) return y < other.y;
        return x < other.x;
    }
    bool operator==(point &other){
        return ( x == other.x && y == other.y );
    }
    point operator-(point &other){
        return {x-other.x, y-other.y};
    }
};

int crossProduct( point &a, point &b, point &c ){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
int crossProduct( point &a, point &b ){
    return a.x*b.y - a.y*b.x;
}

int inside( point &a, point &b, point &c ){
    return crossProduct(a,b,c) >= 0;
}
bool intersection( point &a, point &b, point &c, point &d, point &ans) {
    point temp = b - a;
    point temp1 = d - c;
    int det = crossProduct(temp, temp1);
    if (det == 0) return false; // parallel or collinear

    int z1 = crossProduct(a, b);
    int z2 = crossProduct(c, d);

    ans.x = (ld)(z1 * (c.x - d.x) - z2 * (a.x - b.x)) / det;
    ans.y = (ld)(z1 * (c.y - d.y) - z2 * (a.y - b.y)) / det;

    return true;
}

vector<point> hull( vector<point> &a ){
    if ( a.size() <= 1 ) return a;

	vector<point> v = a;
    sort(v.begin(), v.end());

    vector<point> up, dn;

    for (auto& p : v) {
        while (up.size() > 1 && crossProduct(up[up.size() - 2], up.back(), p) >= 0) {
            up.pop_back();
        }
        while (dn.size() > 1 && crossProduct(dn[dn.size() - 2], dn.back(), p) <= 0) {
            dn.pop_back();
        }
        up.push_back(p);
        dn.push_back(p);
    }
    v = dn;
    if (v.size() > 1) v.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for ( auto& p : up ) {
        v.push_back(p);
    }
    if ( v.size() == 2 && v[0] == v[1] ) v.pop_back();
    return v;
}

void senritsu() {   

    int n; cin >> n;
    vector<point> a(n); for ( int i = 0; i < n; i++ ) cin >> a[i].x >> a[i].y;
    
    vector<point> h = hull(a);

    debug(hull);

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