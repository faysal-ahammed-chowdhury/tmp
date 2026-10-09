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
 
 
 
 
 
 
 
 
 
 
 
 
// https://codeforces.com/contest/703/problem/D
// https://www.youtube.com/watch?v=3s7h2MHQtxc

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3 ) : ((y < hpow) ? 1 : 2);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

const int N = 1e6+10;
int ans = 0;
int freq[N];
const int block_sz = 1500;
int a[N], b[N], c[N], res[N];
unordered_map<int,int> mp;

struct query {
	int l, r, idx;
	int64_t ord;
 
	inline void calcOrder() {
		ord = hilbertOrder(l, r, 21, 0);
	}
};
bool cmp( query &a, query &b ){
    return a.ord < b.ord;
}
vector<query> q;

void mo(){
    sort(q.begin(), q.end(),cmp); 
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
        q[i-1].calcOrder();
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