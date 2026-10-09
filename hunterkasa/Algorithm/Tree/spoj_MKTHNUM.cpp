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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

const int MAXN = (int)3e5 + 9;
const int MAXV = (int)1e9 + 9; //maximum value of any element in array

//array values can be negative too, use appropriate minimum and maximum value
struct wavelet_tree {
    int lo, hi;
    wavelet_tree *l, *r;
    int *b, *c, bsz, csz; // c holds the prefix sum of elements

    wavelet_tree() {
        lo = 1;
        hi = 0;
        bsz = 0;
        csz = 0, l = NULL;
        r = NULL;
    }

    void init(int *from, int *to, int x, int y) {
        lo = x, hi = y;
        if(from >= to) return;
        int mid = (lo + hi) >> 1;
        auto f = [mid](int x) {
          return x <= mid;
        };
        b = (int*)malloc((to - from + 2) * sizeof(int));
        bsz = 0;
        b[bsz++] = 0;
        c = (int*)malloc((to - from + 2) * sizeof(int));
        csz = 0;
        c[csz++] = 0;
        for(auto it = from; it != to; it++) {
          b[bsz] = (b[bsz - 1] + f(*it));
          c[csz] = (c[csz - 1] + (*it));
          bsz++;
          csz++;
        }
        if(hi == lo) return;
        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree();
        l->init(from, pivot, lo, mid);
        r = new wavelet_tree();
        r->init(pivot, to, mid + 1, hi);
    }
    //kth smallest element in [l, r]
    //for array [1,2,1,3,5] 2nd smallest is 1 and 3rd smallest is 2
    int kth(int l, int r, int k) {
        if(l > r) return 0;
        if(lo == hi) return lo;
        int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
        if(k <= inLeft) return this->l->kth(lb + 1, rb, k);
        return this->r->kth(l - lb, r - rb, k - inLeft);
    }
    //count of numbers in [l, r] Less than or equal to k
    int LTE(int l, int r, int k) {
        if(l > r || k < lo) return 0;
        if(hi <= k) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
    }
    //count of numbers in [l, r] equal to k
    int count(int l, int r, int k) {
        if(l > r || k < lo || k > hi) return 0;
        if(lo == hi) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        int mid = (lo + hi) >> 1;
        if(k <= mid) return this->l->count(lb + 1, rb, k);
        return this->r->count(l - lb, r - rb, k);
    }
    //sum of numbers in [l ,r] less than or equal to k
    int sum(int l, int r, int k) {
        if(l > r or k < lo) return 0;
        if(hi <= k) return c[r] - c[l - 1];
        int lb = b[l - 1], rb = b[r];
        return this->l->sum(lb + 1, rb, k) + this->r->sum(l - lb, r - rb, k);
    }
    ~wavelet_tree() {
        delete l;
        delete r;
    }
};

int a[MAXN];
wavelet_tree t;

void tohka(){

    int n,q;
	cin >> n >> q;
	for ( int i = 1; i <= n; i++ ) cin >> a[i];

    // make sure to compress the data 
    set<int> st(a+1,a+1+n);
    map<int,int> mp, mp1;
    int cnt = 0;
    for ( auto e : st ){
        if ( !mp.count(e) ){
            mp[e] = cnt;
            mp1[cnt] = e;
            cnt++;
        }
    }
    for ( int i = 1; i <= n; i++ ){
        a[i] = mp[a[i]];
    }
    
    t.init(a+1,a+1+n,-MAXV,MAXV);
	while(q-- > 0){
        int l, r, k;    cin >> l >> r >> k;
        cout << mp1[t.kth(l, r, k)] << endl;
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