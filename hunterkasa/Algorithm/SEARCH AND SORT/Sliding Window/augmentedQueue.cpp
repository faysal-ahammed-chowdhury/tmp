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
typedef long long ll;
typedef long double ld;
#define int long long




struct AggStack{
    stack<pair<bitset<1001>,int>> st;
    void push( int x ){ 
        bitset<1001> b;
        if ( st.empty() ){
            b.reset();
            b[0] = 1;
            b[x] = 1;
        } else {
            b = st.top().first;
            b |= ( b << x );
            b[x] = 1;
        }
        st.push({b,x});
    }
    void pop(){ // remove oldest element
        st.pop();
    }
    int get( int x ){ // return if s is in the stack
        return st.top().first[x];
    }
    int getVal(){ 
        return st.top().second;
    }
    bool empty(){
        return st.empty();
    }
};
struct AggQueue{
    AggStack in, out;
    void push( int x ){
        in.push(x);
    }
    void transfer(){
        while ( !in.empty() ){
            int x = in.getVal(); in.pop();
            out.push(x);
        }
    }
    void pop(){
        if ( out.empty() ) transfer();
        if ( !out.empty() ) out.pop();
    }
    bool check( int s ){
        int x = 0;
        if ( out.empty() ) return in.get(s);
        if ( in.empty() ) return out.get(s);
        for ( int i = 0; i <= s && !x; i++ ){
            x |= ( in.get(i) && out.get(s-i) );
        }
        return x;
    }
};

void senritsu() {
    // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/I
    int n, s;  cin >> n >> s;
    int a[n]; for ( int i = 0; i < n; i++ ) cin >> a[i];

    AggQueue aq;

    int l = 0, ans = INT_MAX;

    for ( int r = 0; r < n; r++ ){
        aq.push(a[r]);
        while ( l <= r && aq.check(s) ){
            ans = min( ans, r - l + 1 ); 
            aq.pop();
            l++;
        }
    }

    cout << ( ans == INT_MAX ? -1 : ans ) << endl;

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