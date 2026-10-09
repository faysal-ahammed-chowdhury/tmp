#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
 
void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
#define int long long
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
const ll N = 100000+1000;
const ll block_sz = sqrt(N)+10;
ll freq[N], mo_cnt = 0, ret[N];
ll a[N];
ll freq1[N];
ll mxid = 0;
ll n,m;
inline void add( ll idx ){
    freq[a[idx]]++;
    freq1[freq[a[idx]]]++;
    if ( freq[a[idx]] > mxid )
        mxid = freq[a[idx]];
    while ( freq1[mxid+1] ){
        mxid++;
    }
}
inline void erase( ll idx ){
    freq1[freq[a[idx]]]--;
    freq[a[idx]]--;
    while ( !freq1[mxid] ){
        mxid--;
    }
}
 
struct query{
    ll l, r, idx;
    query(){}
    query( ll _l, ll _r, ll _i ) : l(_l), r(_r), idx(_i){}
    bool operator < (const query &p) const{
        if ( l/block_sz != p.l/block_sz ) return l < p.l;
        return ((l/block_sz)&1) ? r > p.r : r < p.r;
    }
};
void mo( vector<query> &q ){
    sort(q.begin(), q.end()); 
    ll cur_l = 1, cur_r = 0; // if 1-indexed array
    // int l = 0, r = -1;
    for ( auto &qq : q ){
        while (cur_l > qq.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < qq.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < qq.l) {
            erase(cur_l);
            cur_l++;
        }
        while (cur_r > qq.r) {
            erase(cur_r);
            cur_r--;
        }
 
        
        if ( mxid < 0 )
            mxid = 0;
        if ( mxid > n )
            mxid = n;
        ret[qq.idx] = mxid;
    }
}
void tohka(){
    cin >> n;
    cin >> m;
    for ( ll i = 1; i <= n; i++ )  cin >> a[i];
    vector<query> q;
    for ( ll i = 1; i <= m; i++ ){
        ll l, r; cin >> l >> r; l++; r++;
        q.push_back({l,r,i});
    }
    mo(q);
    for ( ll i = 1; i <= m; i++ ){
        cout << ret[i] << endl;
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