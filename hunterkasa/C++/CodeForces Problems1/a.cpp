#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugArr(a, n)
#endif

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'

void Wah() {
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt","w",stdout);
    #endif
}

typedef vector<long long> vll;
typedef long double ld;
#define int long long
#define ll long long
typedef pair<int,int> pii;


struct trie {
    struct node{
        node *head[2];
        int cnt;
        node(){
            head[0] = head[1] = NULL;
            cnt = 0;
        }
    } *root;

    trie(){ root = new node(); }
    ~trie() { del(root); }
    
    void insert( int val ){
        node *cur = root;
        for ( int i = 30; i >= 0; i-- ){
            int x = (( val >> i ) & 1);
            if ( cur->head[x] == NULL ) cur->head[x] = new node();
            cur = cur->head[x];
            cur->cnt++;
        }
    }
    
    void erase( int val ){
        node *cur = root;
        for ( int i = 30; i >= 0; i-- ){
            int x = ( (val >> i) & 1 );
            cur = cur->head[x];
            cur->cnt--;
        }
    }
    
    int query_min( int val ){
        node *cur = root;
        int sum = 0;
        for ( int i = 30; i >= 0; i-- ){
            int x = (val >> i) & 1;
            if ( cur->head[x] != NULL && cur->head[x]->cnt > 0   ){
                cur = cur->head[x];
            } else {
                cur = cur->head[x^1];
                sum |= (1<<i);
            }
        }
        return sum;
    }

    int query_max( int val ){
        node *cur = root;
        int sum = 0;
        for ( int i = 30; i >= 0; i-- ){
            int x = ((val >> i) & 1) ^ 1;
            if ( cur->head[x] != NULL && cur->head[x]->cnt > 0 ){
                cur = cur->head[x];
                sum |= (1<<i);
            } else {
                cur = cur->head[x^1];
            }
        }
        return sum;
    }

    int query_kth( int val, int k ){
        node *cur = root;
        int ans = 0;
        for ( int i = 30; i >= 0; i-- ){
            if ( cur == NULL ) break;
            int x = val >> i & 1; 
            int cnt = 0;
            if ( cur->head[x] != NULL ) cnt = cur->head[x]->cnt;
            if ( k <= cnt ){
                cur = cur->head[x];
                ans <<= 1ll;
            } else {
                k -= cnt;
                cur = cur->head[x^1];
                ans <<= 1ll;
                ans++;
            }
        }
        return ans;
    }

    void del( node *cur ){
        if ( cur->head[0] ) del(cur->head[0]);
        if ( cur->head[1] ) del(cur->head[1]);
        delete(cur);
    }
    
};

void senritsu() {
    
    int n, q; cin >> n >> q;
    vector<int> a(n); for ( int i = 0; i < n; i++ ) cin >> a[i];

    vll all;
    sort(a.begin(), a.end());
    all.push_back(a.back()-a[0]);

    if ( a.front() == a.back() ) {
        while ( q-- > 0 ){
            int x; cin >> x;
            cout << 0 << endl;
        }
        return;
    }

    while ( 1 ){

        trie t; for ( auto c : a ) t.insert(c);

        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;

        for ( int i = 0; i < n; i++ ){
            pq.push({t.query_kth(a[i],2),i,2});
        }

        int cnt = 0;
        vll temp;
        while ( !pq.empty() && cnt < 2 * n ) {
            auto [x,idx,k] = pq.top(); pq.pop();
            cnt++;
            if ( cnt % 2 == 0 ) temp.push_back(x);
            if ( k + 1 <= n ) pq.push({ t.query_kth(a[idx],k+1), idx, k+1 });
        } 

        all.push_back(temp.back() - temp[0]);

        a = temp;
        if ( all.back() == 0 ) break;

    }

    while ( q-- > 0 ){
        int x; cin >> x;
        cout << all[ min( x, (int)all.size() - 1 ) ] << endl;
    }

}

signed main() {
    // 君は分かってるかな 教えてくれた 戻らないその幸せは
    Wah();
    int tt = 1;
    cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}