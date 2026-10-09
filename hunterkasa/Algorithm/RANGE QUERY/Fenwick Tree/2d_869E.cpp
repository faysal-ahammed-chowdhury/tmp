#include <bits/stdc++.h>
using namespace std;


#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            '\n'

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
typedef long double ld;
#define int long long






const int N = 2500+10;
int tree[N][N];
int tree1[N][N];

void update( int x, int y, int val ){
    for (int i = x; i < N; i = i | (i + 1))
        for (int j = y; j < N; j = j | (j + 1))
            tree[i][j] += val;
}
void update1( int x, int y, int val ){
    for (int i = x; i < N; i = i | (i + 1))
        for (int j = y; j < N; j = j | (j + 1))
            tree1[i][j] += val;
}

int query( int x, int y ){
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += tree[i][j];
    return ret;
}
int query1( int x, int y ){
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += tree1[i][j];
    return ret;
}

void range_add( int x1, int y1, int x2, int y2, int z ){
    update(x1, y1, z);
    update(x2+1, y1, -z);
    update(x1, y2+1, -z);
    update(x2+1, y2+1, z);
}
void range_add1( int x1, int y1, int x2, int y2, int z ){
    update1(x1, y1, z);
    update1(x2+1, y1, -z);
    update1(x1, y2+1, -z);
    update1(x2+1, y2+1, z);
}


ll mval = 1e10;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
int myrand(int mod) {
    return mt()%mod;
}


void tohka(){

    int n, m, q;    cin >> n >> m >> q;
    map< array<int,4>, int > mp;   
    map< array<int,4>, int > mp1;   

    while ( q-- ){
        
        int type, X, Y, XX, YY; cin >> type >> X >> Y >> XX >> YY;

        if ( type == 1 ){

            int temp = myrand(mval);
            int temp1 = myrand(mval);

            range_add(X,Y,XX,YY,temp);
            range_add1(X,Y,XX,YY,temp1);


            mp[{X,Y,XX,YY}] = temp;
            mp1[{X,Y,XX,YY}] = temp1;
            
        } else if ( type == 2 ){
            
            int temp = -mp[{X,Y,XX,YY}];
            int temp1 = -mp1[{X,Y,XX,YY}];

            range_add(X,Y,XX,YY,temp);
            range_add1(X,Y,XX,YY,temp1);

            mp.erase({X,Y,XX,YY});
            mp1.erase({X,Y,XX,YY});

        } else {
            if ( query(X,Y) == query(XX,YY) && query1(X,Y) == query1(XX,YY) ){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }

        }

    } 


}   

signed main(){
    fast();
    int tt = 1;
    // cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        tohka();
    }      
    return 0;
}        