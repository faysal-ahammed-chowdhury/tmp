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
#define int unsigned long long

 
 













const int N = 3e5+100;
const int block_sz = sqrt(N);
ll freq[(int)1e6+100], mo_cnt = 0, ret[(int)1e6+100];
ll a[N];

inline void add( int idx ){
    freq[a[idx]]++;
    if ( freq[a[idx]] == 1 )
        mo_cnt++;
}

inline void erase( int idx ){
    freq[a[idx]]--;
    if ( freq[a[idx]] == 0 )    
        mo_cnt--;
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
    int l = 1, r = 0; // if 1-indexed array
    // int l = 0, r = -1;
    mo_cnt = 0;
    for ( auto &qq : q ){
        while ( qq.l < l ) add(--l);
        while ( qq.l > l ) erase(l++);
        while ( qq.r < r ) erase(r--);
        while ( qq.r > r ) add(++r);
        ret[qq.idx] = mo_cnt;
    }
}

void tohka(){
    
    memset(ret,-1,sizeof ret);
    memset(freq,0,sizeof freq);

    int n, q;   cin >> n >> q;
    for ( int i = 1; i <= n; i++ )  cin >> a[i];
    vector<query> qq;
    for ( int i = 1; i <= q; i++ ){
        int l, r;   cin >> l >> r;
        qq.push_back({l,r,i});
    }

    mo(qq);

    for ( int i = 1; i <= q; i++ ){
        cout << ret[i] << endl;
    }

}

signed main(){
    fast(); 
    ll tt = 1;
    cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ":" << endl;
        tohka();
    }      
    return 0;
} 