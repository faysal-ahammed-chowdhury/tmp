#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debuga(a, n)
#endif
 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'
 
void Wah(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
#define int long long
 




struct Trie {
    struct Node {
        Node *arr[2];
        int prefix[2];

        Node() {
            memset(arr, 0, sizeof arr);
            memset(prefix, 0, sizeof prefix);
        }
    };

    Node *root = new Node();

    void insert(int val) {
        Node *curr = root;
        for (int i = 32; i >= 0; --i) {
            int mask = ((val >> i) & 1);
            if (curr->arr[mask] == 0) curr->arr[mask] = new Node();
            curr->prefix[mask]++;
            curr = curr->arr[mask];
        }
    }

    void remove(Node *curr, int val, int idx) {
        if (idx == -1) return;
        int mask = ((val >> idx) & 1);
        remove(curr->arr[mask], val, idx - 1);
        curr->prefix[mask]--;
        if (curr->prefix[mask] == 0) {
            delete curr->arr[mask];
            curr->arr[mask] = 0;
        }
    }

    void remove(int val) {
        remove(root, val, 32);
    }

    int get_max_xor(int val) {
        Node *curr = root;
        int ret = 0;
        for (int i = 32; i >= 0; --i) {
            int mask = (((val >> i) & 1) ^ 1);
            if (curr->arr[mask] != 0) {
                ret |= (1LL << i);
                curr = curr->arr[mask];
            } else if (curr->arr[mask ^ 1] != 0) curr = curr->arr[mask ^ 1];
            else return ret;
        }
        return ret;
    }

    int get_min_xor(int val) {
        Node *curr = root;
        int ret = 0;
        for (int i = 32; i >= 0; --i) {
            int mask = (((val >> i) & 1));
            if (curr->arr[mask] != 0) {
                curr = curr->arr[mask];
            } else if (curr->arr[mask ^ 1] != 0) {
                ret |= (1LL << i);
                curr = curr->arr[mask ^ 1];
            } else return ret;
        }
        return ret;
    }

    bool find(int val) {
        Node *curr = root;
        for (int i = 32; i >= 0; --i) {
            int mask = (val >> i) & 1;
            if (curr->arr[mask] == 0) return 0;
            curr = curr->arr[mask];
        }
        return 1;
    }
} tr;

const int N = 1e6;
vll g[N];
int a[N];
int ans = 0;

void dfs( int x, int p ){
    tr.insert(a[x]);
    for ( auto c : g[x] ){
        if ( c == p ) continue;
        dfs(c,x);
    }
    tr.remove(a[x]);
    ans = max( ans, tr.get_max_xor(a[x]) );
}

void AmeDoko(){

    int n; cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];

    for ( int i = 0; i < n-1; i++ ){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs( 1, -1 );

    cout << ans << endl;

}   
 
signed main(){
    Wah();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        AmeDoko();
    }      
    return 0;
}         