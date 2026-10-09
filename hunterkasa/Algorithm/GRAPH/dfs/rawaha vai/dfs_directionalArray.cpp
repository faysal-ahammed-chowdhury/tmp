//https://lightoj.com/problem/guilty-prince
#include <bits/stdc++.h>
using namespace std;

char mat[1002][1002];

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int vis[1002][1002];

int n, m;

bool valid( int x, int y ){
    if ( x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && mat[x][y] != '#')
        return true;
    return false;
} 
int cnt = 0;
void dfs(int x, int y){
    vis[x][y] = 1;
    cnt++;
    for( int i = 0; i < 4; i++ ){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if ( valid(newx, newy ) == true ){
            dfs(newx,newy);
        }
    }
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;  cin >> t;
    int i = 1;
    while(t--){
        int pi , pj;
        cin >> m >> n;
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < m; j++ ){
                cin >> mat[i][j];
                if ( mat[i][j] == '@' )
                    pi = i, pj = j;
            }
        }
        dfs(pi,pj);
        // int cnt = 0;
        // for ( int i = 0; i < n; i++ ){
        //     for ( int j = 0; j < m; j++ ){
        //         if ( vis[i][j] == 0 && mat[i][j] != '#' ){
        //             // cnt++;
        //             dfs(i,j);
        //         }
        //     }
        // }
        cout << "Case " << i++ << ": "; 
        cout << cnt << endl;
        memset(mat,0,sizeof(mat));
        memset(vis,0,sizeof(vis));
        cnt = 0;
    }

}