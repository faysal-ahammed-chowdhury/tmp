#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int vis[100005];

int dx[] = {0,0,1,-1, 1 ,1,1 ,1};
int dy[] = {1,-1,0,0, -1,1,-1,1};



int n, m;

void dfs(int node){
    vis[node] = 1;
    for ( int i = 0; i < graph[node].size(); i++ ){
        int x = graph[node][i];
        if ( !vis[x] ){
            dfs(x);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ){
        int a,b;    cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cnt = 0;
    for ( int i = 1; i <= n; i++ ){
        if ( vis[i] == 0 ){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}