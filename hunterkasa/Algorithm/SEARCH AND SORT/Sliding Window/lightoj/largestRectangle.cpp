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
#define int long long
 


int largestRectangleArea( vector<int> &h ){
    int n = h.size();
    stack<int> st;
    int leftsmaller[n]{}, rightsmaller[n]{};
    for ( int i = 0; i < n; i++ ){
        while ( !st.empty() && h[st.top()] >= h[i] ) st.pop();
        if ( st.empty() ) leftsmaller[i] = 0;
        else leftsmaller[i] = st.top()+1;
        st.push(i);
    }
    while ( !st.empty() ) st.pop();
    for ( int i = n-1; i >= 0; i-- ){
        while ( !st.empty() && h[st.top()] >= h[i] ) st.pop();
        if ( st.empty() ) rightsmaller[i] = n-1;
        else rightsmaller[i] = st.top()-1;
        st.push(i);
    }
    int maxarea = 0;
    for ( int i = 0; i < n; i++ ){
        maxarea = max( maxarea, h[i] * ( rightsmaller[i] - leftsmaller[i] + 1 ) );
    }
    return maxarea;
}

void samekoSaba(){

    int n, m; cin >> n >> m;
    int a[n][m];
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            char c; cin >> c;
            a[i][j] = ( c == '1' ? 0 : 1 );
        }
    }

    int ans = 0;
    vector<int> h(m,0);
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            if ( a[i][j] == 1 ) h[j]++;
            else h[j] = 0;
        }
        ans = max( ans, largestRectangleArea(h) );
    }
    cout << ans << endl;

}


 
signed main(){
    Wah();
    int tt = 1;
    cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ": ";
        samekoSaba();
    }      
    return 0;
}