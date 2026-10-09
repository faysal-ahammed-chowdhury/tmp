// https://codeforces.com/contest/1514/problem/D
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
const int N = 3e5+100;
const int block_sz = sqrt(N);
ll freq[(int)1e6+100], mo_cnt = 0, ret[(int)1e6+100];
ll freqfreq[(int)1e6+100];
ll a[N];
ll mxid = 0;
inline void add(ll x){
    freqfreq[freq[a[x]]]--;
    freq[a[x]]++;
    freqfreq[freq[a[x]]]++;
    mxid = max(mxid,freq[a[x]]);
}
inline void erase(ll x){
    freqfreq[freq[a[x]]]--;
    if ( freqfreq[freq[a[x]]] == 0 && mxid == freq[a[x]] )
        mxid--;
    freq[a[x]]--;
    freqfreq[freq[a[x]]]++;
}
struct query{
    int l, r, idx;
    query(){}
    query( int _l, int _r, int _i ) : l(_l), r(_r), idx(_i){}
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
        while (cur_r < qq.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_r > qq.r) {
            erase(cur_r);
            cur_r--;
        }
        while (cur_l < qq.l) {
            erase(cur_l);
            cur_l++;
        }
        while (cur_l > qq.l) {
            cur_l--;
            add(cur_l);
        }

        int dif = qq.r - qq.l + 1;
        if ( mxid <= (dif+1)/2 )
            ret[qq.idx] = 1ll;
        else 
            ret[qq.idx] = 2*mxid - dif;
    }
}

void tohka(){
    int n, m;
    cin >> n >> m;
    for ( ll i = 1; i <= n; i++ )  cin >> a[i];
    vector<query> q;
    for ( ll i = 1; i <= m; i++ ){
        ll l, r; cin >> l >> r;
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