#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<vi> vmi;
typedef vector<vpi> vmpi;

const int INF = 1e9 + 19;
const int LIM = 1e5 + 15;

int n, m;
vmpi G;
vb mark;
vi dist;

void dijkstra(int s){
    fill(dist.begin(),dist.end(), LIM);
    
    set<pi> S;
    S.insert({dist[s] = 0, s});
    while(!S.empty()){
        int u = S.begin() -> se;
        S.erase(S.begin());
        
        for(auto v : G[u])
        {
            if(dist[v.fi] > dist[u] + v.se)
            {
                S.erase({dist[v.fi], v.fi});
                dist[v.fi] = dist[u] + v.se;
                S.insert({dist[v.fi], v.fi});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    G.resize(n + 1);
    mark.assign(n + 1, false);
    dist.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, s, c;
        cin >> u >> s >> c;
        G[u].pb({s, c});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);
    if (dist[t] == INF)
        cout << "There is no path from " << s << " to " << t;
    else 
        cout << "Min distance(" << s << " -> " << t << ") = " << dist[t];
        
    return 0;
}