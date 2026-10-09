#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            "\n"
 
void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
 
 
 
 
 
 
 
 
 
 
 
 
 



const int N = 1e6+10;
int ans = 0;
int freq[N];
const int block_sz = 1500;
int a[N], b[N], c[N], res[N];
unordered_map<int,int> mp;

struct query{
    int l, r, idx;
    query(){}
    query( int _l, int _r, int _i ) : l(_l), r(_r), idx(_i){}
    bool operator < (const query &p) const{
        if ( l/block_sz != p.l/block_sz ) return l < p.l;
        return ((l/block_sz)&1) ? r > p.r : r < p.r;
    }
};
vector<query> q;

void mo(){
    sort(q.begin(), q.end()); 
    // ll cr = 1, cl = 0; // if 1-indexed array
    int cl = 0, cr = -1;
    int l,r;
    for ( auto &qq : q ){
        l = qq.l;
        r = qq.r;
        
        while (cr < r){
            cr++;
            if (freq[c[cr]] > 0)
                ans ^= a[cr];
            freq[c[cr]]++;
        }
        while (cl > l){
            cl--;
            if (freq[c[cl]] > 0)
                ans ^= a[cl];
            freq[c[cl]]++;
        }
        while (cr > r){
            freq[c[cr]]--;
            if (freq[c[cr]] != 0)
                ans ^= a[cr];
            cr--;
        }
        while (cl < l){
            freq[c[cl]]--;
            if (freq[c[cl]] != 0)
                ans ^= a[cl];
            cl++;
        }
 
        res[qq.idx] = ans;
    }
}
void tohka(){

    int n;  cin >> n;
    int ans = 0;
    for ( int i = 1; i <= n; i++ ) cin >> a[i], b[i] = a[i];

    sort(b+1,b+1+n);
    int cnt = 1;
    for ( int i = 1; i <= n; i++ ){
        if ( !mp[b[i]] ){
            mp[b[i]] = cnt;
            cnt++;
        }
    }
    for ( int i = 1; i <= n; i++ ){
        c[i] = mp[a[i]];
    }
    
    int Q;  cin >> Q;
    for ( int i = 1; i <= Q; i++ ){
        int l,r;    cin >> l >> r;
        q.push_back({l,r,i});
    }
    mo();
    for ( int i = 1; i <= Q; i++ ){
        cout << res[i] << endl;
    }

}
 
signed main(){
    fast(); 
    ll tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        tohka();
    }      
    return 0;
}  