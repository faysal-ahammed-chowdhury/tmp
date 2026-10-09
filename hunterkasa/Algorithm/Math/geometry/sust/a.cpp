// angle from center vector

void senritsu() {   

    ld x, y; cin >> x >> y;

    ld a = atan2(y,x);
    ld pi = acos(-1);
    if ( a < 0 ) a += 2*pi;
    cout << fixed << setprecision(17) << a;

}

// angle between 2 vector

ld dot( pair<ld,ld> a, pair<ld,ld> b ){
    return a.first * b.first + a.second * b.second;
}
ld mag( pair<ld,ld> x ){
    return sqrtl(x.first*x.first + x.second*x.second);
}
 
void senritsu() {   
 
    pair<ld,ld> a,b; cin >> a.first >> a.second >> b.first >> b.second;
 
    ld x = acos(dot(a,b)/(mag(a)*mag(b)));
    ld pi = acos(-1);
    if ( x < 0 ) x += pi;
 
    cout << fixed << setprecision(10) << x << endl;
}
 

// shoelace 

struct point{
    int x, y;
    bool operator<(const point &other)const{
        if ( x == other.x ) return y < other.y;
        return x < other.x;
    }
    bool operator==(const point &other)const{
        return ( x == other.x && y == other.y );
    }
    point operator-(const point &other)const{
        return {x-other.x, y-other.y};
    }
};
 
ld areaOfPolygon( vector<point> a ){
    if ( a.size() < 3 ) return 0.0;
 
    a.push_back(a[0]);
    int n = a.size();
    ld ans = 0;
    
    for ( int i = 0; i < n-1; i++ ){
        ans += a[i].x*a[i+1].y;
        ans -= a[i].y*a[i+1].x;
    }
    if ( ans < 0 ) ans = -ans;
    return ans/2.0;
}

ld dist( pair<ld,ld> a, pair<ld,ld> b ){
    return sqrt(powl(a.first - b.first,2) + powl(a.second - b.second,2) );
}


int getPointsBetween2point( point a, point b ){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return gcd(dx,dy);
}