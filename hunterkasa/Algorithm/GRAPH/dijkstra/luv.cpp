#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
const int INF = INT_MAX;

vector<pair<long,long>> g[N];

void dijkstra(int source){
    vector<int> dist(N,INF);
    vector<int> vis(N,0);
 
    set<pair<int,int>> st;

    st.insert({0,source});
    dist[source] = 0;

    while( st.size() > 0 ){
        auto node = *st.begin();
        int v = node.second;
        int v_dis = node.first;
        
        st.erase(st.begin());
        if (vis[v]) continue;
        
        vis[v] = 1;

        for ( auto child: g[v] ){
            int child_v = child.first;
            int wt = child.second;

            if ( dist[v] + wt < dist[child_v] ){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            } 
        }
    }
}

int main(){
    int n, m;
    for ( int i = 0; i < m; i++ ){
        int x, y, wt;   cin >> x >> y >> wt;
        g[x].push_back({y,wt});
        // g[y].push_back({x,wt});
    }
}