// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;

char mat[1002][1002];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int vis[1002][1002];

int n, m;

void dfs(int x, int y){
    vis[x][y] = 1;

    if ( y+1 < m && vis[x][y+1] == 0 && mat[x][y+1] != '#'){
        dfs(x,y+1);
    }
    if ( y-1 >= 0 && vis[x][y-1] == 0 && mat[x][y-1] != '#'){
        dfs(x,y-1);
    }
    if ( x-1 >= 0 && vis[x-1][y] == 0 && mat[x-1][y] != '#'){
        dfs(x-1,y);
    }
    if ( x+1 < n && vis[x+1][y] == 0 && mat[x+1][y] != '#'){
        dfs(x+1,y);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            cin >> mat[i][j];
        }
    }

    int cnt = 0;
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            if ( vis[i][j] == 0 && mat[i][j] != '#' ){
                cnt++;
                dfs(i,j);
            }
        }
    }

    cout << cnt << endl;

}