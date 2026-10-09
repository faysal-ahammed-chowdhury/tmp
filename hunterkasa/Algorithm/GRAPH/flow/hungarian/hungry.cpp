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
 
 



const int N = 100;
struct Hungarian {
    long long c[N][N], fx[N], fy[N], d[N];
    int l[N], r[N], arg[N], trace[N];
    queue<int> q;
    int start, finish, n;
    const long long inf = 1e18;
    Hungarian() {}
    Hungarian(int n1, int n2) : n(max(n1, n2)) {
        for (int i = 1; i <= n; ++i) {
            fy[i] = l[i] = r[i] = 0;
            for (int j = 1; j <= n; ++j) c[i][j] = inf; // make it 0 for maximum cost matching (not necessarily with max count of matching)
        }
    }
    void add_edge(int u, int v, long long cost) {
        c[u][v] = min(c[u][v], cost);
    }
    inline long long getC(int u, int v) {
        return c[u][v] - fx[u] - fy[v];
    }
    void initBFS() {
        while (!q.empty()) q.pop();
        q.push(start);
        for (int i = 0; i <= n; ++i) trace[i] = 0;
        for (int v = 1; v <= n; ++v) {
            d[v] = getC(start, v);
            arg[v] = start;
        }
        finish = 0;
    }
    void findAugPath() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= n; ++v) if (!trace[v]) {
                long long w = getC(u, v);
                if (!w) {
                    trace[v] = u;
                    if (!r[v]) {
                        finish = v;
                        return;
                    }
                    q.push(r[v]);
                }
                if (d[v] > w) {
                    d[v] = w;
                    arg[v] = u;
                }
            }
        }
    }
    void subX_addY() {
        long long delta = inf;
        for (int v = 1; v <= n; ++v) if (trace[v] == 0 && d[v] < delta) {
            delta = d[v];
        }
        // Rotate
        fx[start] += delta;
        for (int v = 1; v <= n; ++v) if (trace[v]) {
            int u = r[v];
            fy[v] -= delta;
            fx[u] += delta;
        }
        else d[v] -= delta;
        for (int v = 1; v <= n; ++v) if (!trace[v] && !d[v]) {
            trace[v] = arg[v];
            if (!r[v]) {
                finish = v;
                return;
            }
            q.push(r[v]);
        }
    }
    void Enlarge() {
        do {
            int u = trace[finish];
            int nxt = l[u];
            l[u] = finish;
            r[finish] = u;
            finish = nxt;
        } while (finish);
    }
    long long maximum_matching() {
        for (int u = 1; u <= n; ++u) {
            fx[u] = c[u][1];
            for (int v = 1; v <= n; ++v) {
                fx[u] = min(fx[u], c[u][v]);
            }
        }
        for (int v = 1; v <= n; ++v) {
            fy[v] = c[1][v] - fx[1];
            for (int u = 1; u <= n; ++u) {
                fy[v] = min(fy[v], c[u][v] - fx[u]);
            }
        }
        for (int u = 1; u <= n; ++u) {
            start = u;
            initBFS();
            while (!finish) {
                findAugPath();
                if (!finish) subX_addY();
            }
            Enlarge();
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (c[i][l[i]] != inf) ans += c[i][l[i]];
            else l[i] = 0;
        }
        return ans;
    }
};


void AmeSameDoko(){

    int n; cin >> n;
    int a[n+1], b[n+1];
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    for ( int i = 1; i <= n; i++ ) cin >> b[i];

    Hungarian h(n,n);

    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= n; j++ ){
            if ( a[i] > b[j] )
                h.add_edge(i,j,-2);
            if ( a[i] == b[j] ) 
                h.add_edge(i,j,-1);
        }
    }

    cout << -h.maximum_matching() << endl;
    
}
 
signed main(){
    Wah();
    int tt = 1;
    cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ": ";
        AmeSameDoko();
    }      
    return 0;
}