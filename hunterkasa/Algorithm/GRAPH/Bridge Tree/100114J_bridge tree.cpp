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



struct TECC { // 0 indexed
    int n, k;
    vector<vector<int>> g, t;
    vector<bool> used;
    vector<int> comp, ord, low, dist, reap;
    using edge = pair<int, int>;
    vector<edge> br;
    void dfs(int x, int prv, int& c) {
        used[x] = 1; ord[x] = c++; low[x] = n;
        bool mul = 0; // int children=0;
        for (auto y : g[x]) {
            if (used[y]) {
                if (y != prv || mul) low[x] = min(low[x], ord[y]);
                else mul = 1;
                continue;
            }
            dfs(y, x, c);
            low[x] = min(low[x], low[y]);
            // if (low[to] >= tin[v] && p!=-1)
            //     IS_CUTPOINT(v);
            // ++children;
        }
        // if(p == -1 && children > 1)
        //     IS_CUTPOINT(v);
    }
    void dfs2(int x, int num) {
        comp[x] = num;
        if ( reap.size() <= num ) reap.resize(num + 1);
        reap[num] = x;
        for (auto y : g[x]) {
            if (comp[y] != -1) continue;
            if (ord[x] < low[y]) {
                br.push_back({ x, y });
                k++;
                dfs2(y, k);
            }
            else dfs2(y, num);
        }
    }
    TECC(const vector<vector<int>>& g) : g(g), n(g.size()), used(n), comp(n, -1), ord(n), low(n), k(0) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            dfs(i, -1, c);
            dfs2(i, k);
            k++;
        }
    }
    void build_tree() {
        t.resize(k);
        for (auto e : br) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
    void dfsD(int x, int p) {
        for (auto c : t[x]) {
            if (c == p) continue;
            dist[c] = dist[x] + 1;
            dfsD(c, x);
        }
    }
    pair<int,int> diameter(){
        dist.resize(k);
        fill(dist.begin(),dist.end(),0);
        dfsD(0,0);
        int x = 0, id = 0;
        for ( int i = 0; i < k; i++ ){
            if ( x < dist[i] ){
                x = dist[i];
                id = i;
            }
        }
        fill(dist.begin(),dist.end(),0);
        dfsD(id,id);
        int xx = 0, idd = 0;
        for ( int i = 0; i < k; i++ ){
            if ( xx < dist[i] ){
                xx = dist[i];
                idd = i;
            }
        }
        return { reap[id]+1, reap[idd]+1 };
    }
};

void senritsu() {   
    
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for ( int i = 0; i < m; i++ ){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    TECC bt(g);

    bt.build_tree();

    pair<int,int> ans = bt.diameter();
    cout << ans.first << ' ' << ans.second << endl;

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

