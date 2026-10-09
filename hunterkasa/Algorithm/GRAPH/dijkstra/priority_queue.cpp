#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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

void dijkstra(int s)
{
    fill(all(dist), +INF);
    fill(all(mark), false);
    
    priority_queue<pi, vpi, less<pi> > pq;
    pq.push({dist[s] = 0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        pq.pop();
        
        if (mark[u]) continue; else mark[u] = true;
        for(auto v : G[u])
        {
            if (dist[v.fi] > dist[u] + v.se)
            {
                dist[v.fi] = dist[u] + v.se;
                pq.push({dist[v.fi], v.fi});
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
        int u, v, c;
        cin >> u >> v >> c;
        G[u].pb({v, c});
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